#include <nan.h>

const int maxValue = 100;  
int numberOfCalls = 0;

void WhoIsThis(const Nan::FunctionCallbackInfo<v8::Value>& args) {  
  
  auto message =  Nan::New<v8::String>("I'm a duck too!").ToLocalChecked();
  args.GetReturnValue().Set(message);
}

void Increment(const Nan::FunctionCallbackInfo<v8::Value>& args) {  
 
  if (!args[0]->IsNumber()) {
    Nan::ThrowError("Argument must be a number");
    return;
  }

  double argsValue = args[0]->NumberValue();
  if (numberOfCalls + argsValue > maxValue) {
    Nan::ThrowError("Counter went through the roof!");
    return;
  }

  numberOfCalls += argsValue;

  auto currentNumberOfCalls =
    Nan::New<v8::Number>(numberOfCalls);

  args.GetReturnValue().Set(currentNumberOfCalls);
}

NAN_MODULE_INIT(Initialize) {  
  NAN_EXPORT(target, WhoIsThis);
  NAN_EXPORT(target, Increment);
}



NODE_MODULE(module_name, Initialize)  