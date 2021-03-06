#ifndef APPJS_UTIL
#define APPJS_UTIL

#include <node.h>

namespace appjs {

char* V8StringToChar(v8::Handle<v8::String> str);
char* V8StringToFunctionChar(v8::Handle<v8::String> str);

class Settings {
public:
  Settings(v8::Local<v8::Object>);
  ~Settings(){}

  bool isNull(const char*);
  bool has(const char*);
  double getNumber(const char*,double);
  char* getString(const char*,char*);
  bool getBoolean(const char*,bool);

private:
  v8::Local<v8::Object> settings_;
  v8::Local<v8::Value> get(const char*);
};

}
#endif
