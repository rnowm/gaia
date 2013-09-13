/* THIS FILE IS AUTOGENERATED - DO NOT EDIT */

#ifndef mozilla_dom_NavigatorBinding_h__
#define mozilla_dom_NavigatorBinding_h__

#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/BindingUtils.h"
#include "mozilla/dom/CallbackFunction.h"
#include "mozilla/dom/CallbackInterface.h"
#include "mozilla/dom/DOMJSClass.h"
#include "mozilla/dom/DOMJSProxyHandler.h"

class nsISupports;
class nsIVariant;

namespace mozilla {
namespace dom {

class MozDOMGetUserMediaErrorCallback;
class MozDOMGetUserMediaSuccessCallback;
class MozGetUserMediaDevicesSuccessCallback;
class MozIdleObserver;
class Navigator;
class systemMessageCallback;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

template <>
struct PrototypeTraits<prototypes::id::Navigator>
{
  enum
  {
    Depth = 0
  };
  typedef mozilla::dom::Navigator NativeType;
};
template <>
struct PrototypeIDMap<mozilla::dom::Navigator>
{
  enum
  {
    PrototypeID = prototypes::id::Navigator
  };
};
} // namespace dom
} // namespace mozilla


namespace mozilla {
namespace dom {

class systemMessageCallback : public CallbackFunction
{
public:
  explicit inline systemMessageCallback(JSObject* aCallback)
    : CallbackFunction(aCallback)
  {
  }

  explicit inline systemMessageCallback(CallbackFunction* aOther)
    : CallbackFunction(aOther)
  {
  }

  template <typename T>
  inline void
  Call(const T& thisObj, const Optional<JS::Handle<JSObject*> >& message, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    JS::Rooted<JSObject*> thisObjJS(s.GetContext(),
      WrapCallThisObject(s.GetContext(), CallbackPreserveColor(), thisObj));
    if (!thisObjJS) {
      aRv.Throw(NS_ERROR_FAILURE);
      return;
    }
    return Call(s.GetContext(), thisObjJS, message, aRv);
  }

  inline void
  Call(const Optional<JS::Handle<JSObject*> >& message, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    return Call(s.GetContext(), JS::NullPtr(), message, aRv);
  }

private:
  void Call(JSContext* cx, JS::Handle<JSObject*> aThisObj, const Optional<JS::Handle<JSObject*> >& message, ErrorResult& aRv);
};


class MozDOMGetUserMediaSuccessCallback : public CallbackFunction
{
public:
  explicit inline MozDOMGetUserMediaSuccessCallback(JSObject* aCallback)
    : CallbackFunction(aCallback)
  {
  }

  explicit inline MozDOMGetUserMediaSuccessCallback(CallbackFunction* aOther)
    : CallbackFunction(aOther)
  {
  }

  template <typename T>
  inline void
  Call(const T& thisObj, nsISupports* value, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    JS::Rooted<JSObject*> thisObjJS(s.GetContext(),
      WrapCallThisObject(s.GetContext(), CallbackPreserveColor(), thisObj));
    if (!thisObjJS) {
      aRv.Throw(NS_ERROR_FAILURE);
      return;
    }
    return Call(s.GetContext(), thisObjJS, value, aRv);
  }

  inline void
  Call(nsISupports* value, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    return Call(s.GetContext(), JS::NullPtr(), value, aRv);
  }

private:
  void Call(JSContext* cx, JS::Handle<JSObject*> aThisObj, nsISupports* value, ErrorResult& aRv);
};


class MozDOMGetUserMediaErrorCallback : public CallbackFunction
{
public:
  explicit inline MozDOMGetUserMediaErrorCallback(JSObject* aCallback)
    : CallbackFunction(aCallback)
  {
  }

  explicit inline MozDOMGetUserMediaErrorCallback(CallbackFunction* aOther)
    : CallbackFunction(aOther)
  {
  }

  template <typename T>
  inline void
  Call(const T& thisObj, const nsAString& error, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    JS::Rooted<JSObject*> thisObjJS(s.GetContext(),
      WrapCallThisObject(s.GetContext(), CallbackPreserveColor(), thisObj));
    if (!thisObjJS) {
      aRv.Throw(NS_ERROR_FAILURE);
      return;
    }
    return Call(s.GetContext(), thisObjJS, error, aRv);
  }

  inline void
  Call(const nsAString& error, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    return Call(s.GetContext(), JS::NullPtr(), error, aRv);
  }

private:
  void Call(JSContext* cx, JS::Handle<JSObject*> aThisObj, const nsAString& error, ErrorResult& aRv);
};


class MozGetUserMediaDevicesSuccessCallback : public CallbackFunction
{
public:
  explicit inline MozGetUserMediaDevicesSuccessCallback(JSObject* aCallback)
    : CallbackFunction(aCallback)
  {
  }

  explicit inline MozGetUserMediaDevicesSuccessCallback(CallbackFunction* aOther)
    : CallbackFunction(aOther)
  {
  }

  template <typename T>
  inline void
  Call(const T& thisObj, nsIVariant* devices, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    JS::Rooted<JSObject*> thisObjJS(s.GetContext(),
      WrapCallThisObject(s.GetContext(), CallbackPreserveColor(), thisObj));
    if (!thisObjJS) {
      aRv.Throw(NS_ERROR_FAILURE);
      return;
    }
    return Call(s.GetContext(), thisObjJS, devices, aRv);
  }

  inline void
  Call(nsIVariant* devices, ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions)
  {
    CallSetup s(CallbackPreserveColor(), aRv, aExceptionHandling);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    return Call(s.GetContext(), JS::NullPtr(), devices, aRv);
  }

private:
  void Call(JSContext* cx, JS::Handle<JSObject*> aThisObj, nsIVariant* devices, ErrorResult& aRv);
};


namespace NavigatorBinding {

  extern const NativePropertyHooks sNativePropertyHooks;

  void
  CreateInterfaceObjects(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JS::Heap<JSObject*>* protoAndIfaceArray);

  inline JS::Handle<JSObject*> GetProtoObject(JSContext* aCx, JS::Handle<JSObject*> aGlobal)
  {

    /* Get the interface prototype object for this class.  This will create the
       object as needed. */

    /* Make sure our global is sane.  Hopefully we can remove this sometime */
    if (!(js::GetObjectClass(aGlobal)->flags & JSCLASS_DOM_GLOBAL)) {
      return JS::NullPtr();
    }
    /* Check to see whether the interface objects are already installed */
    JS::Heap<JSObject*>* protoAndIfaceArray = GetProtoAndIfaceArray(aGlobal);
    if (!protoAndIfaceArray[prototypes::id::Navigator]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /*
     * The object might _still_ be null, but that's OK.
     *
     * Calling fromMarkedLocation() is safe because protoAndIfaceArray is
     * traced by TraceProtoAndIfaceCache() and its contents are never
     * changed after they have been set.
     */
    return JS::Handle<JSObject*>::fromMarkedLocation(protoAndIfaceArray[prototypes::id::Navigator].address());
  }

  inline JS::Handle<JSObject*> GetConstructorObject(JSContext* aCx, JS::Handle<JSObject*> aGlobal)
  {

    /* Get the interface object for this class.  This will create the object as
       needed. */

    /* Make sure our global is sane.  Hopefully we can remove this sometime */
    if (!(js::GetObjectClass(aGlobal)->flags & JSCLASS_DOM_GLOBAL)) {
      return JS::NullPtr();
    }
    /* Check to see whether the interface objects are already installed */
    JS::Heap<JSObject*>* protoAndIfaceArray = GetProtoAndIfaceArray(aGlobal);
    if (!protoAndIfaceArray[constructors::id::Navigator]) {
      CreateInterfaceObjects(aCx, aGlobal, protoAndIfaceArray);
    }

    /*
     * The object might _still_ be null, but that's OK.
     *
     * Calling fromMarkedLocation() is safe because protoAndIfaceArray is
     * traced by TraceProtoAndIfaceCache() and its contents are never
     * changed after they have been set.
     */
    return JS::Handle<JSObject*>::fromMarkedLocation(protoAndIfaceArray[constructors::id::Navigator].address());
  }

  JSObject*
  DefineDOMInterface(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JS::Handle<jsid> id, bool* aEnabled);

  extern DOMJSClass Class;

  JSObject*
  Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, mozilla::dom::Navigator* aObject, nsWrapperCache* aCache);

  template <class T>
  inline JSObject* Wrap(JSContext* aCx, JS::Handle<JSObject*> aScope, T* aObject)
  {
    return Wrap(aCx, aScope, aObject, aObject);
  }

} // namespace NavigatorBinding



class MozIdleObserver : public CallbackInterface
{
public:
  explicit inline MozIdleObserver(JSObject* aCallback)
    : CallbackInterface(aCallback)
  {
  }

  void Onidle(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  void Onactive(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);

  uint32_t GetTime(ErrorResult& aRv, ExceptionHandling aExceptionHandling = eReportExceptions);
};


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_NavigatorBinding_h__
