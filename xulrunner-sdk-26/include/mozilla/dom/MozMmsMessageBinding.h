/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_MozMmsMessageBinding_h__
#define mozilla_dom_MozMmsMessageBinding_h__

#include "jsapi.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"
#include "nsIDOMFile.h"

class nsIDOMBlob;

namespace mozilla {
namespace dom {

struct MmsAttachment : public MainThreadDictionaryBase
{
  nsRefPtr<nsIDOMBlob> mContent;
  nsString mId;
  nsString mLocation;

private:
  static bool initedIds;
  static jsid content_id;
  static jsid id_id;
  static jsid location_id;

  MmsAttachment(const MmsAttachment&) MOZ_DELETE;

public:
  inline MmsAttachment()
  {
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value");

  bool
  Init(const nsAString& aJSON);

  bool
  ToObject(JSContext* cx, JS::Handle<JSObject*> parentObject, JS::MutableHandle<JS::Value> rval) const;

  void
  TraceDictionary(JSTracer* trc);

private:
  static bool
  InitIds(JSContext* cx);
};
struct MmsAttachmentInitializer : public MmsAttachment
{
  inline MmsAttachmentInitializer()
  {
    // Safe to pass a null context if we pass a null value
    Init(nullptr, JS::NullHandleValue);
  }
};


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_MozMmsMessageBinding_h__
