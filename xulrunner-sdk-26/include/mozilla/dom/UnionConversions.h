#ifndef mozilla_dom_UnionConversions_h__
#define mozilla_dom_UnionConversions_h__

#include "CanvasRenderingContext2DBinding.h"
#include "EventBinding.h"
#include "HTMLCanvasElementBinding.h"
#include "HTMLElementBinding.h"
#include "HTMLImageElementBinding.h"
#include "HTMLOptGroupElementBinding.h"
#include "HTMLOptionElementBinding.h"
#include "HTMLVideoElementBinding.h"
#include "XPCWrapper.h"
#include "mozilla/dom/UnionTypes.h"
#include "nsDOMQS.h"
#include "nsDebug.h"

namespace mozilla {
namespace dom {

class EventOrStringArgument {
public:
  // Argument needs to be a const ref because that's all Maybe<> allows
  EventOrStringArgument(const EventOrString& aUnion) : mUnion(const_cast<EventOrString&>(aUnion))
  {
  }

  bool TrySetToEvent(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    {
      nsresult rv = UnwrapObject<prototypes::id::Event, nsDOMEvent>(cx, &value.toObject(), SetAsEvent());
      if (NS_FAILED(rv)) {
        if (mUnion.mType != mUnion.eUninitialized) {
          mUnion.DestroyEvent();
        }tryNext = true;
        return true;
      }
    }
    return true;
  }

  bool TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    if (!ConvertJSValueToString(cx, value, pvalue, eStringify, eStringify, mStringHolder)) {
      return false;
    }
    SetAsString() = &mStringHolder;
    return true;
  }

private:
  NonNull<nsDOMEvent>& SetAsEvent()
  {
    mUnion.mType = mUnion.eEvent;
    return mUnion.mValue.mEvent.SetValue();
  }
  NonNull<nsAString>& SetAsString()
  {
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }

  FakeDependentString mStringHolder;

  EventOrString& mUnion;
};


class HTMLElementOrLongArgument {
public:
  // Argument needs to be a const ref because that's all Maybe<> allows
  HTMLElementOrLongArgument(const HTMLElementOrLong& aUnion) : mUnion(const_cast<HTMLElementOrLong&>(aUnion))
  {
  }

  bool TrySetToHTMLElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    {
      nsresult rv = UnwrapObject<prototypes::id::HTMLElement, nsGenericHTMLElement>(cx, &value.toObject(), SetAsHTMLElement());
      if (NS_FAILED(rv)) {
        if (mUnion.mType != mUnion.eUninitialized) {
          mUnion.DestroyHTMLElement();
        }tryNext = true;
        return true;
      }
    }
    return true;
  }

  bool TrySetToLong(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    if (!ValueToPrimitive<int32_t, eDefault>(cx, value, &SetAsLong())) {
      return false;
    }
    return true;
  }

private:
  NonNull<nsGenericHTMLElement>& SetAsHTMLElement()
  {
    mUnion.mType = mUnion.eHTMLElement;
    return mUnion.mValue.mHTMLElement.SetValue();
  }
  int32_t& SetAsLong()
  {
    mUnion.mType = mUnion.eLong;
    return mUnion.mValue.mLong.SetValue();
  }

  HTMLElementOrLong& mUnion;
};


class HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument {
public:
  // Argument needs to be a const ref because that's all Maybe<> allows
  HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElementArgument(const HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement& aUnion) : mUnion(const_cast<HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement&>(aUnion))
  {
  }

  bool TrySetToHTMLImageElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    {
      nsresult rv = UnwrapObject<prototypes::id::HTMLImageElement, mozilla::dom::HTMLImageElement>(cx, &value.toObject(), SetAsHTMLImageElement());
      if (NS_FAILED(rv)) {
        if (mUnion.mType != mUnion.eUninitialized) {
          mUnion.DestroyHTMLImageElement();
        }tryNext = true;
        return true;
      }
    }
    return true;
  }

  bool TrySetToHTMLCanvasElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    {
      nsresult rv = UnwrapObject<prototypes::id::HTMLCanvasElement, mozilla::dom::HTMLCanvasElement>(cx, &value.toObject(), SetAsHTMLCanvasElement());
      if (NS_FAILED(rv)) {
        if (mUnion.mType != mUnion.eUninitialized) {
          mUnion.DestroyHTMLCanvasElement();
        }tryNext = true;
        return true;
      }
    }
    return true;
  }

  bool TrySetToHTMLVideoElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    {
      nsresult rv = UnwrapObject<prototypes::id::HTMLVideoElement, mozilla::dom::HTMLVideoElement>(cx, &value.toObject(), SetAsHTMLVideoElement());
      if (NS_FAILED(rv)) {
        if (mUnion.mType != mUnion.eUninitialized) {
          mUnion.DestroyHTMLVideoElement();
        }tryNext = true;
        return true;
      }
    }
    return true;
  }

private:
  NonNull<mozilla::dom::HTMLImageElement>& SetAsHTMLImageElement()
  {
    mUnion.mType = mUnion.eHTMLImageElement;
    return mUnion.mValue.mHTMLImageElement.SetValue();
  }
  NonNull<mozilla::dom::HTMLCanvasElement>& SetAsHTMLCanvasElement()
  {
    mUnion.mType = mUnion.eHTMLCanvasElement;
    return mUnion.mValue.mHTMLCanvasElement.SetValue();
  }
  NonNull<mozilla::dom::HTMLVideoElement>& SetAsHTMLVideoElement()
  {
    mUnion.mType = mUnion.eHTMLVideoElement;
    return mUnion.mValue.mHTMLVideoElement.SetValue();
  }

  HTMLImageElementOrHTMLCanvasElementOrHTMLVideoElement& mUnion;
};


class HTMLOptionElementOrHTMLOptGroupElementArgument {
public:
  // Argument needs to be a const ref because that's all Maybe<> allows
  HTMLOptionElementOrHTMLOptGroupElementArgument(const HTMLOptionElementOrHTMLOptGroupElement& aUnion) : mUnion(const_cast<HTMLOptionElementOrHTMLOptGroupElement&>(aUnion))
  {
  }

  bool TrySetToHTMLOptionElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    {
      nsresult rv = UnwrapObject<prototypes::id::HTMLOptionElement, mozilla::dom::HTMLOptionElement>(cx, &value.toObject(), SetAsHTMLOptionElement());
      if (NS_FAILED(rv)) {
        if (mUnion.mType != mUnion.eUninitialized) {
          mUnion.DestroyHTMLOptionElement();
        }tryNext = true;
        return true;
      }
    }
    return true;
  }

  bool TrySetToHTMLOptGroupElement(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    {
      nsresult rv = UnwrapObject<prototypes::id::HTMLOptGroupElement, mozilla::dom::HTMLOptGroupElement>(cx, &value.toObject(), SetAsHTMLOptGroupElement());
      if (NS_FAILED(rv)) {
        if (mUnion.mType != mUnion.eUninitialized) {
          mUnion.DestroyHTMLOptGroupElement();
        }tryNext = true;
        return true;
      }
    }
    return true;
  }

private:
  NonNull<mozilla::dom::HTMLOptionElement>& SetAsHTMLOptionElement()
  {
    mUnion.mType = mUnion.eHTMLOptionElement;
    return mUnion.mValue.mHTMLOptionElement.SetValue();
  }
  NonNull<mozilla::dom::HTMLOptGroupElement>& SetAsHTMLOptGroupElement()
  {
    mUnion.mType = mUnion.eHTMLOptGroupElement;
    return mUnion.mValue.mHTMLOptGroupElement.SetValue();
  }

  HTMLOptionElementOrHTMLOptGroupElement& mUnion;
};


class StringOrCanvasGradientOrCanvasPatternArgument {
public:
  // Argument needs to be a const ref because that's all Maybe<> allows
  StringOrCanvasGradientOrCanvasPatternArgument(const StringOrCanvasGradientOrCanvasPattern& aUnion) : mUnion(const_cast<StringOrCanvasGradientOrCanvasPattern&>(aUnion))
  {
  }

  bool TrySetToString(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    if (!ConvertJSValueToString(cx, value, pvalue, eStringify, eStringify, mStringHolder)) {
      return false;
    }
    SetAsString() = &mStringHolder;
    return true;
  }

  bool TrySetToCanvasGradient(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    {
      nsresult rv = UnwrapObject<prototypes::id::CanvasGradient, mozilla::dom::CanvasGradient>(cx, &value.toObject(), SetAsCanvasGradient());
      if (NS_FAILED(rv)) {
        if (mUnion.mType != mUnion.eUninitialized) {
          mUnion.DestroyCanvasGradient();
        }tryNext = true;
        return true;
      }
    }
    return true;
  }

  bool TrySetToCanvasPattern(JSContext* cx, JS::Handle<JS::Value> value, JS::MutableHandle<JS::Value> pvalue, bool& tryNext)
  {
    tryNext = false;
    {
      nsresult rv = UnwrapObject<prototypes::id::CanvasPattern, mozilla::dom::CanvasPattern>(cx, &value.toObject(), SetAsCanvasPattern());
      if (NS_FAILED(rv)) {
        if (mUnion.mType != mUnion.eUninitialized) {
          mUnion.DestroyCanvasPattern();
        }tryNext = true;
        return true;
      }
    }
    return true;
  }

private:
  NonNull<nsAString>& SetAsString()
  {
    mUnion.mType = mUnion.eString;
    return mUnion.mValue.mString.SetValue();
  }
  NonNull<mozilla::dom::CanvasGradient>& SetAsCanvasGradient()
  {
    mUnion.mType = mUnion.eCanvasGradient;
    return mUnion.mValue.mCanvasGradient.SetValue();
  }
  NonNull<mozilla::dom::CanvasPattern>& SetAsCanvasPattern()
  {
    mUnion.mType = mUnion.eCanvasPattern;
    return mUnion.mValue.mCanvasPattern.SetValue();
  }

  FakeDependentString mStringHolder;

  StringOrCanvasGradientOrCanvasPattern& mUnion;
};


} // namespace dom
} // namespace mozilla


#endif // mozilla_dom_UnionConversions_h__
