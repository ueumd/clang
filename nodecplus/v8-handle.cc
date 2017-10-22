#include <node.h>
#include <v8.h>
#include <iostream>
using namespace v8;

static int globalValue = 0;
static Isolate *globalIsolate = NULL;

void globalFun(const v8::FunctionCallbackInfo<Value> &args)
{
	printf("js call C++ \"globalFun\"\n");
}

int main(int argc, const char * argv[])
{
	//省略部份声明代码，参考上面
	Local<FunctionTemplate> globalFunTemplate = v8::FunctionTemplate::New(globalIsolate, (FunctionCallback)globalFun);
	global->Set(v8::String::NewFromUtf8(globalIsolate, "globalFun"), globalFunTemplate);

	Local<String> source = String::NewFromUtf8(globalIsolate, "globalFun();");
	Local<Script> script = Script::Compile(source);
	Local<Value> result = script->Run();
}