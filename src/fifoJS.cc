#define BUILDING_NODE_EXTENSION
#include <node.h>

using namespace v8;

Handle<Value> mkfifoFunc(const Arguments& args) {
  HandleScope scope;

  if (args.Length() < 2) {
    ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
    return scope.Close(Undefined());
  }

  if (!args[0]->IsString() || !args[1]->IsNumber()) {
    ThrowException(Exception::TypeError(String::New("Wrong arguments")));
    return scope.Close(Undefined());
  }
 
  String::Utf8Value utfStr(args[0]);
  char* s = (char*) *utfStr;

  if (mkfifo(s, args[1]->NumberValue())) {
    ThrowException(Exception::TypeError(String::New("Error creating pipe")));
    return scope.Close(Undefined());
  }

  return scope.Close(Undefined());
}

void Init(Handle<Object> target) {
  target->Set(String::NewSymbol("mkfifo"),
      FunctionTemplate::New(mkfifoFunc)->GetFunction());
}

NODE_MODULE(fifoJS, Init)
