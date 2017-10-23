#include <node.h>
#include <v8.h>
#include <iostream>

using namespace v8;
// http://developer.51cto.com/art/201612/525379.htm
// 传入了两个参数，args[0] 字符串，args[1] 回调函数
void hello(const FunctionCallbackInfo<Value>& args) {
  // 使用 HandleScope 来管理生命周期
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  // 判断参数格式和格式
  if (args.Length() < 2 || !args[0]->IsString()) {
    isolate->ThrowException(Exception::TypeError( String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  }

  // callback, 使用Cast方法来转换
  Local<Function> callback = Local<Function>::Cast(args[1]);
  Local<Value> argv[1] = {
    // 拼接String
    String::Concat(Local<String>::Cast(args[0]), String::NewFromUtf8(isolate, " world"))
  };
  // 调用回调, 参数: 当前上下文，参数个数，参数列表
  callback->Call(isolate->GetCurrentContext()->Global(), 1, argv);
}

// 这个函数会返回一个带有 x，y 和 z 三个元素的新数组
Local<Array> NewPointArray(int x, int y, int z) {
	v8::Isolate* isolate = v8::Isolate::GetCurrent();

	// 我们将会创建一些临时的句柄，所以我们先创建一个句柄域
	EscapableHandleScope handle_scope(isolate);

	// 创建一个空数组
	Local<Array> array = Array::New(isolate, 3);

	// 如果在创建数组时产生异常，则返回一个空数组
	if (array.IsEmpty())
		return Local<Array>();

	// 填充数组
	array->Set(0, Integer::New(isolate, x));
	array->Set(1, Integer::New(isolate, y));
	array->Set(2, Integer::New(isolate, z));

	// 通过 Escape 返回该数组
	return handle_scope.Escape(array);
}

// 相当于在 exports 对象中添加 { hello: hello }
void init(Handle<Object> exports) {
  NODE_SET_METHOD(exports, "hello", hello);
  NODE_SET_METHOD(exports, "hello", NewPointArray);
}


// 将 export 对象暴露出去
// 原型 `NODE_MODULE(module_name, Initialize)`
NODE_MODULE(test, init)