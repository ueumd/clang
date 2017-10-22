#include <node.h>
#include <v8.h>
#include <iostream>
using namespace v8;

class Person {
private:
	String::Utf8Value *firstName;
	String::Utf8Value *lastName;
public:
	Person(Handle<v8::Value> firstValue, Handle<v8::Value> LastValue) {
		this->firstName = new String::Utf8Value(firstValue);
		this->lastName = new String::Utf8Value(LastValue);
	}

	~Person() {
		delete firstName;
		delete lastName;
	}

	void sayHello() {
		printf("Hello, My Name is: \"%s %s\"\n", **firstName, **lastName);
	}
};

static int globalValue = 0;
static Isolate *globalIsolate = NULL;

void globalGetter(Local<String> property, PropertyCallbackInfo<Value>& info)
{
	info.GetReturnValue().Set(v8::Integer::New(globalIsolate, globalValue));
	printf("js read \"globalValue\"\n");
}

void globalSetter(Local<String> property, Local<Value> value, const PropertyCallbackInfo<void>& info)
{
	globalValue = value->Int32Value();
	printf("js change \"globalValue: %d\"\n", globalValue);
}

void globalFun(const v8::FunctionCallbackInfo<Value> &args)
{
	printf("js call C++ \"globalFun\"\n");
}

void Person_SayHello(const v8::FunctionCallbackInfo<Value> &args)
{
	Local<Object> self = args.Holder();
	Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
	void *ptr = wrap->Value();
	static_cast<Person*>(ptr)->sayHello();
}

void createPerson(const v8::FunctionCallbackInfo<Value> &args)
{
	if (args.Length() >= 2) {
		Local<Object> self = args.Holder();
		Person *person = new Person(args[0], args[1]);

		self->SetInternalField(0, External::New(globalIsolate, person));
		args.GetReturnValue().Set(self);
	}
}

void testCallJS()
{
	Isolate* callJSISolate = Isolate::GetCurrent();
	//HandleScope scope(globalIsolate);
	
	//v8::Isolate *callJSISolate = v8::Isolate::New();
	v8::Isolate::Scope isolate_scope(callJSISolate);

	HandleScope handle_scope(callJSISolate);
	v8::Handle<Context> context = v8::Context::New(callJSISolate);

	v8::Context::Scope contextScope(context);
	v8::Local<String> source = String::NewFromUtf8(callJSISolate, "function Person() { this.name = 'Kevin'; } Person.prototype.getName = function () { return this.name; }; var p = new Person();");
	v8::Local<Script> script = v8::Script::Compile(source);
	script->Run();

	v8::Handle<Value> data_p = context->Global()->Get(String::NewFromUtf8(callJSISolate, "p"));
	v8::Handle<Object> object_p = Handle<Object>::Cast(data_p);
	v8::Handle<Function> getName = Handle<Function>::Cast(object_p->Get(String::NewFromUtf8(callJSISolate, "getName")));
	Handle<Value> value = getName->Call(object_p, 0, NULL);

	String::Utf8Value utf8(value);
	printf("call js function result: %s\n", *utf8);
}

int main(int argc, const char * argv[])
{
	v8::V8::InitializeICU();
	v8::V8::Initialize();

	Isolate* globalIsolate = Isolate::GetCurrent();
	HandleScope scope(globalIsolate);

	//globalIsolate = Isolate::New();

	Isolate::Scope isolate_scope(globalIsolate);
	HandleScope handle_scope(globalIsolate);

	v8::Handle<v8::ObjectTemplate> global = v8::ObjectTemplate::New(globalIsolate);
	//全局变量，通过Getter，Setter方法访问和设置
	global->SetAccessor(v8::String::NewFromUtf8(globalIsolate, "globalValue"), (AccessorGetterCallback)globalGetter, (AccessorSetterCallback)globalSetter);

	//全局函数，供JS访问
	Local<FunctionTemplate> globalFunTemplate = v8::FunctionTemplate::New(globalIsolate, (FunctionCallback)globalFun);
	global->Set(v8::String::NewFromUtf8(globalIsolate, "globalFun"), globalFunTemplate);

	//JS访问C++类及对象方法
	v8::Local<FunctionTemplate> personClass = v8::FunctionTemplate::New(globalIsolate, (FunctionCallback)createPerson);
	personClass->SetClassName(v8::String::NewFromUtf8(globalIsolate, "Person"));
	v8::Handle<ObjectTemplate>p_Prototype = personClass->PrototypeTemplate();
	p_Prototype->Set(String::NewFromUtf8(globalIsolate, "sayHello"), FunctionTemplate::New(globalIsolate, Person_SayHello));
	v8::Handle<ObjectTemplate> personInst = personClass->InstanceTemplate();
	personInst->SetInternalFieldCount(1);
	global->Set(v8::String::NewFromUtf8(globalIsolate, "Person"), personClass);

	Local<Context> context = Context::New(globalIsolate, NULL, global);
	Context::Scope context_scope(context);

	Local<String> source = String::NewFromUtf8(globalIsolate, "var tmpValue = globalValue; globalValue = 4; globalFun(); var p = new Person('Kevin', 'Lu'); p.sayHello();");
	Local<Script> script = Script::Compile(source);
	Local<Value> result = script->Run();

	String::Utf8Value utf8(result);
	printf("Script Run Result: %s\n", *utf8);

	testCallJS();
	v8::V8::Dispose();

	return 0;
}