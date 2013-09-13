#ifndef mozilla_dom_UnionTypes_h__
#define mozilla_dom_UnionTypes_h__

#include "mozilla/dom/BindingUtils.h"

namespace mozilla {
namespace dom {
class CanvasGradient;
class CanvasPattern;
class HTMLCanvasElement;
class HTMLImageElement;
class HTMLOptGroupElement;
class HTMLOptionElement;
class HTMLVideoElement;
} // namespace dom
} // namespace mozilla
class nsDOMEvent;
class nsGenericHTMLElement;

namespace mozilla {
namespace dom {

class EventOrString {
public:
  EventOrString() : mType(eUninitialized)
  {
  }
  ~EventOrString()
  {
    switch (mType) {
      case eEvent:
         DestroyEvent();
         break;
      case eString:
         DestroyString();
         break;
      case eUninitialized:
        break;
    }
  }

  bool IsEvent() const
  {
    return mType == eEvent;
  }
  nsDOMEvent& GetAsEvent() const
  {
    MOZ_ASSERT(IsEvent(), "Wrong type!");
    return const_cast<NonNull<nsDOMEvent>&>(mValue.mEvent.Value());
  }

  bool IsString() const
  {
    return mType == eString;
  }
  const nsAString& GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return const_cast<NonNull<nsAString>&>(mValue.mString.Value());
  }

  NonNull<nsDOMEvent>& SetAsEvent()
  {
    mType = eEvent;
    return mValue.mEvent.SetValue();
  }

  NonNull<nsAString>& SetAsString()
  {
    mType = eString;
    return mValue.mString.SetValue();
  }

  bool ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj,
               JS::MutableHandle<JS::Value> rval) const;

private:
  friend class EventOrStringArgument;

  void DestroyEvent()
  {
    MOZ_ASSERT(IsEvent(), "Wrong type!");
    mValue.mEvent.Destroy();
    mType = eUninitialized;
  }
  void DestroyString()
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    mValue.mString.Destroy();
    mType = eUninitialized;
  }

  enum Type {
    eUninitialized,
    eEvent,
    eString
  };
  union Value {
    UnionMember<NonNull<nsDOMEvent> > mEvent;
    UnionMember<NonNull<nsAString> > mString;
  };

  Type mType;
  Value mValue;
};



class HTMLElementOrLong {
public:
  HTMLElementOrLong() : mType(eUninitialized)
  {
  }
  ~HTMLElementOrLong()
  {
    switch (mType) {
      case eHTMLElement:
         DestroyHTMLElement();
         break;
      case eLong:
         DestroyLong();
         break;
      case eUninitialized:
        break;
    }
  }

  bool IsHTMLElement() const
  {
    return mType == eHTMLElement;
  }
  nsGenericHTMLElement& GetAsHTMLElement() const
  {
    MOZ_ASSERT(IsHTMLElement(), "Wrong type!");
    return const_cast<NonNull<nsGenericHTMLElement>&>(mValue.mHTMLElement.Value());
  }

  bool IsLong() const
  {
    return mType == eLong;
  }
  int32_t GetAsLong() const
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    return const_cast<int32_t&>(mValue.mLong.Value());
  }

  NonNull<nsGenericHTMLElement>& SetAsHTMLElement()
  {
    mType = eHTMLElement;
    return mValue.mHTMLElement.SetValue();
  }

  int32_t& SetAsLong()
  {
    mType = eLong;
    return mValue.mLong.SetValue();
  }

  bool ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj,
               JS::MutableHandle<JS::Value> rval) const;

private:
  friend class HTMLElementOrLongArgument;

  void DestroyHTMLElement()
  {
    MOZ_ASSERT(IsHTMLElement(), "Wrong type!");
    mValue.mHTMLElement.Destroy();
    mType = eUninitialized;
  }
  void DestroyLong()
  {
    MOZ_ASSERT(IsLong(), "Wrong type!");
    mValue.mLong.Destroy();
    mType = eUninitialized;
  }

  enum Type {
    eUninitialized,
    eHTMLElement,
    eLong
  };
  union Value {
    UnionMember<NonNull<nsGenericHTMLElement> > mHTMLElement;
    UnionMember<int32_t > mLong;
  };

  Type mType;
  Value mValue;
};



class HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement {
public:
  HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement() : mType(eUninitialized)
  {
  }
  ~HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement()
  {
    switch (mType) {
      case eHTMLImageElement:
         DestroyHTMLImageElement();
         break;
      case eHTMLCanvasElement:
         DestroyHTMLCanvasElement();
         break;
      case eHTMLVideoElement:
         DestroyHTMLVideoElement();
         break;
      case eUninitialized:
        break;
    }
  }

  bool IsHTMLImageElement() const
  {
    return mType == eHTMLImageElement;
  }
  mozilla::dom::HTMLImageElement& GetAsHTMLImageElement() const
  {
    MOZ_ASSERT(IsHTMLImageElement(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::HTMLImageElement>&>(mValue.mHTMLImageElement.Value());
  }

  bool IsHTMLCanvasElement() const
  {
    return mType == eHTMLCanvasElement;
  }
  mozilla::dom::HTMLCanvasElement& GetAsHTMLCanvasElement() const
  {
    MOZ_ASSERT(IsHTMLCanvasElement(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::HTMLCanvasElement>&>(mValue.mHTMLCanvasElement.Value());
  }

  bool IsHTMLVideoElement() const
  {
    return mType == eHTMLVideoElement;
  }
  mozilla::dom::HTMLVideoElement& GetAsHTMLVideoElement() const
  {
    MOZ_ASSERT(IsHTMLVideoElement(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::HTMLVideoElement>&>(mValue.mHTMLVideoElement.Value());
  }

  NonNull<mozilla::dom::HTMLImageElement>& SetAsHTMLImageElement()
  {
    mType = eHTMLImageElement;
    return mValue.mHTMLImageElement.SetValue();
  }

  NonNull<mozilla::dom::HTMLCanvasElement>& SetAsHTMLCanvasElement()
  {
    mType = eHTMLCanvasElement;
    return mValue.mHTMLCanvasElement.SetValue();
  }

  NonNull<mozilla::dom::HTMLVideoElement>& SetAsHTMLVideoElement()
  {
    mType = eHTMLVideoElement;
    return mValue.mHTMLVideoElement.SetValue();
  }

  bool ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj,
               JS::MutableHandle<JS::Value> rval) const;

private:
  friend class HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument;

  void DestroyHTMLImageElement()
  {
    MOZ_ASSERT(IsHTMLImageElement(), "Wrong type!");
    mValue.mHTMLImageElement.Destroy();
    mType = eUninitialized;
  }
  void DestroyHTMLCanvasElement()
  {
    MOZ_ASSERT(IsHTMLCanvasElement(), "Wrong type!");
    mValue.mHTMLCanvasElement.Destroy();
    mType = eUninitialized;
  }
  void DestroyHTMLVideoElement()
  {
    MOZ_ASSERT(IsHTMLVideoElement(), "Wrong type!");
    mValue.mHTMLVideoElement.Destroy();
    mType = eUninitialized;
  }

  enum Type {
    eUninitialized,
    eHTMLImageElement,
    eHTMLCanvasElement,
    eHTMLVideoElement
  };
  union Value {
    UnionMember<NonNull<mozilla::dom::HTMLImageElement> > mHTMLImageElement;
    UnionMember<NonNull<mozilla::dom::HTMLCanvasElement> > mHTMLCanvasElement;
    UnionMember<NonNull<mozilla::dom::HTMLVideoElement> > mHTMLVideoElement;
  };

  Type mType;
  Value mValue;
};



class HTMLOptionElementOrHTMLOptGroupElement {
public:
  HTMLOptionElementOrHTMLOptGroupElement() : mType(eUninitialized)
  {
  }
  ~HTMLOptionElementOrHTMLOptGroupElement()
  {
    switch (mType) {
      case eHTMLOptionElement:
         DestroyHTMLOptionElement();
         break;
      case eHTMLOptGroupElement:
         DestroyHTMLOptGroupElement();
         break;
      case eUninitialized:
        break;
    }
  }

  bool IsHTMLOptionElement() const
  {
    return mType == eHTMLOptionElement;
  }
  mozilla::dom::HTMLOptionElement& GetAsHTMLOptionElement() const
  {
    MOZ_ASSERT(IsHTMLOptionElement(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::HTMLOptionElement>&>(mValue.mHTMLOptionElement.Value());
  }

  bool IsHTMLOptGroupElement() const
  {
    return mType == eHTMLOptGroupElement;
  }
  mozilla::dom::HTMLOptGroupElement& GetAsHTMLOptGroupElement() const
  {
    MOZ_ASSERT(IsHTMLOptGroupElement(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::HTMLOptGroupElement>&>(mValue.mHTMLOptGroupElement.Value());
  }

  NonNull<mozilla::dom::HTMLOptionElement>& SetAsHTMLOptionElement()
  {
    mType = eHTMLOptionElement;
    return mValue.mHTMLOptionElement.SetValue();
  }

  NonNull<mozilla::dom::HTMLOptGroupElement>& SetAsHTMLOptGroupElement()
  {
    mType = eHTMLOptGroupElement;
    return mValue.mHTMLOptGroupElement.SetValue();
  }

  bool ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj,
               JS::MutableHandle<JS::Value> rval) const;

private:
  friend class HTMLOptionElementOrHTMLOptGroupElementArgument;

  void DestroyHTMLOptionElement()
  {
    MOZ_ASSERT(IsHTMLOptionElement(), "Wrong type!");
    mValue.mHTMLOptionElement.Destroy();
    mType = eUninitialized;
  }
  void DestroyHTMLOptGroupElement()
  {
    MOZ_ASSERT(IsHTMLOptGroupElement(), "Wrong type!");
    mValue.mHTMLOptGroupElement.Destroy();
    mType = eUninitialized;
  }

  enum Type {
    eUninitialized,
    eHTMLOptionElement,
    eHTMLOptGroupElement
  };
  union Value {
    UnionMember<NonNull<mozilla::dom::HTMLOptionElement> > mHTMLOptionElement;
    UnionMember<NonNull<mozilla::dom::HTMLOptGroupElement> > mHTMLOptGroupElement;
  };

  Type mType;
  Value mValue;
};



class StringOrCanvasGradientOrCanvasPattern {
public:
  StringOrCanvasGradientOrCanvasPattern() : mType(eUninitialized)
  {
  }
  ~StringOrCanvasGradientOrCanvasPattern()
  {
    switch (mType) {
      case eString:
         DestroyString();
         break;
      case eCanvasGradient:
         DestroyCanvasGradient();
         break;
      case eCanvasPattern:
         DestroyCanvasPattern();
         break;
      case eUninitialized:
        break;
    }
  }

  bool IsString() const
  {
    return mType == eString;
  }
  const nsAString& GetAsString() const
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    return const_cast<NonNull<nsAString>&>(mValue.mString.Value());
  }

  bool IsCanvasGradient() const
  {
    return mType == eCanvasGradient;
  }
  mozilla::dom::CanvasGradient& GetAsCanvasGradient() const
  {
    MOZ_ASSERT(IsCanvasGradient(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::CanvasGradient>&>(mValue.mCanvasGradient.Value());
  }

  bool IsCanvasPattern() const
  {
    return mType == eCanvasPattern;
  }
  mozilla::dom::CanvasPattern& GetAsCanvasPattern() const
  {
    MOZ_ASSERT(IsCanvasPattern(), "Wrong type!");
    return const_cast<NonNull<mozilla::dom::CanvasPattern>&>(mValue.mCanvasPattern.Value());
  }

  NonNull<nsAString>& SetAsString()
  {
    mType = eString;
    return mValue.mString.SetValue();
  }

  NonNull<mozilla::dom::CanvasGradient>& SetAsCanvasGradient()
  {
    mType = eCanvasGradient;
    return mValue.mCanvasGradient.SetValue();
  }

  NonNull<mozilla::dom::CanvasPattern>& SetAsCanvasPattern()
  {
    mType = eCanvasPattern;
    return mValue.mCanvasPattern.SetValue();
  }

  bool ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj,
               JS::MutableHandle<JS::Value> rval) const;

private:
  friend class StringOrCanvasGradientOrCanvasPatternArgument;

  void DestroyString()
  {
    MOZ_ASSERT(IsString(), "Wrong type!");
    mValue.mString.Destroy();
    mType = eUninitialized;
  }
  void DestroyCanvasGradient()
  {
    MOZ_ASSERT(IsCanvasGradient(), "Wrong type!");
    mValue.mCanvasGradient.Destroy();
    mType = eUninitialized;
  }
  void DestroyCanvasPattern()
  {
    MOZ_ASSERT(IsCanvasPattern(), "Wrong type!");
    mValue.mCanvasPattern.Destroy();
    mType = eUninitialized;
  }

  enum Type {
    eUninitialized,
    eString,
    eCanvasGradient,
    eCanvasPattern
  };
  union Value {
    UnionMember<NonNull<nsAString> > mString;
    UnionMember<NonNull<mozilla::dom::CanvasGradient> > mCanvasGradient;
    UnionMember<NonNull<mozilla::dom::CanvasPattern> > mCanvasPattern;
  };

  Type mType;
  Value mValue;
};



class EventOrStringReturnValue {
public:
  EventOrStringReturnValue() : mType(eUninitialized)
  {
  }
  ~EventOrStringReturnValue();

  OwningNonNull<nsDOMEvent>& SetAsEvent();

  nsString& SetAsString();

  bool ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj,
               JS::MutableHandle<JS::Value> rval) const;

private:
  enum Type {
    eUninitialized,
    eEvent,
    eString
  };
  union Value {
    UnionMember<OwningNonNull<nsDOMEvent> > mEvent;
    UnionMember<nsString > mString;
  };

  Type mType;
  Value mValue;
};



class HTMLElementOrLongReturnValue {
public:
  HTMLElementOrLongReturnValue() : mType(eUninitialized)
  {
  }
  ~HTMLElementOrLongReturnValue();

  OwningNonNull<nsGenericHTMLElement>& SetAsHTMLElement();

  int32_t& SetAsLong();

  bool ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj,
               JS::MutableHandle<JS::Value> rval) const;

private:
  enum Type {
    eUninitialized,
    eHTMLElement,
    eLong
  };
  union Value {
    UnionMember<OwningNonNull<nsGenericHTMLElement> > mHTMLElement;
    UnionMember<int32_t > mLong;
  };

  Type mType;
  Value mValue;
};



class HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementReturnValue {
public:
  HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementReturnValue() : mType(eUninitialized)
  {
  }
  ~HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementReturnValue();

  OwningNonNull<mozilla::dom::HTMLImageElement>& SetAsHTMLImageElement();

  OwningNonNull<mozilla::dom::HTMLCanvasElement>& SetAsHTMLCanvasElement();

  OwningNonNull<mozilla::dom::HTMLVideoElement>& SetAsHTMLVideoElement();

  bool ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj,
               JS::MutableHandle<JS::Value> rval) const;

private:
  enum Type {
    eUninitialized,
    eHTMLImageElement,
    eHTMLCanvasElement,
    eHTMLVideoElement
  };
  union Value {
    UnionMember<OwningNonNull<mozilla::dom::HTMLImageElement> > mHTMLImageElement;
    UnionMember<OwningNonNull<mozilla::dom::HTMLCanvasElement> > mHTMLCanvasElement;
    UnionMember<OwningNonNull<mozilla::dom::HTMLVideoElement> > mHTMLVideoElement;
  };

  Type mType;
  Value mValue;
};



class HTMLOptionElementOrHTMLOptGroupElementReturnValue {
public:
  HTMLOptionElementOrHTMLOptGroupElementReturnValue() : mType(eUninitialized)
  {
  }
  ~HTMLOptionElementOrHTMLOptGroupElementReturnValue();

  OwningNonNull<mozilla::dom::HTMLOptionElement>& SetAsHTMLOptionElement();

  OwningNonNull<mozilla::dom::HTMLOptGroupElement>& SetAsHTMLOptGroupElement();

  bool ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj,
               JS::MutableHandle<JS::Value> rval) const;

private:
  enum Type {
    eUninitialized,
    eHTMLOptionElement,
    eHTMLOptGroupElement
  };
  union Value {
    UnionMember<OwningNonNull<mozilla::dom::HTMLOptionElement> > mHTMLOptionElement;
    UnionMember<OwningNonNull<mozilla::dom::HTMLOptGroupElement> > mHTMLOptGroupElement;
  };

  Type mType;
  Value mValue;
};



class StringOrCanvasGradientOrCanvasPatternReturnValue {
public:
  StringOrCanvasGradientOrCanvasPatternReturnValue() : mType(eUninitialized)
  {
  }
  ~StringOrCanvasGradientOrCanvasPatternReturnValue();

  nsString& SetAsString();

  OwningNonNull<mozilla::dom::CanvasGradient>& SetAsCanvasGradient();

  OwningNonNull<mozilla::dom::CanvasPattern>& SetAsCanvasPattern();

  bool ToJSVal(JSContext* cx, JS::Handle<JSObject*> scopeObj,
               JS::MutableHandle<JS::Value> rval) const;

private:
  enum Type {
    eUninitialized,
    eString,
    eCanvasGradient,
    eCanvasPattern
  };
  union Value {
    UnionMember<nsString > mString;
    UnionMember<OwningNonNull<mozilla::dom::CanvasGradient> > mCanvasGradient;
    UnionMember<OwningNonNull<mozilla::dom::CanvasPattern> > mCanvasPattern;
  };

  Type mType;
  Value mValue;
};

} // namespace dom
} // namespace mozilla


#endif // mozilla_dom_UnionTypes_h__
