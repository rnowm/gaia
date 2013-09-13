/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/toolkit/components/downloads/nsIApplicationReputation.idl
 */

#ifndef __gen_nsIApplicationReputation_h__
#define __gen_nsIApplicationReputation_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIApplicationReputationCallback; /* forward declaration */

class nsIApplicationReputationQuery; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIApplicationReputationService */
#define NS_IAPPLICATIONREPUTATIONSERVICE_IID_STR "9c12a510-eb1c-11e2-a98a-fa916188709b"

#define NS_IAPPLICATIONREPUTATIONSERVICE_IID \
  {0x9c12a510, 0xeb1c, 0x11e2, \
    { 0xa9, 0x8a, 0xfa, 0x91, 0x61, 0x88, 0x70, 0x9b }}

class NS_NO_VTABLE nsIApplicationReputationService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLICATIONREPUTATIONSERVICE_IID)

  /* void queryReputation (in nsIApplicationReputationQuery aQuery, in nsIApplicationReputationCallback aCallback); */
  NS_IMETHOD QueryReputation(nsIApplicationReputationQuery *aQuery, nsIApplicationReputationCallback *aCallback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIApplicationReputationService, NS_IAPPLICATIONREPUTATIONSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLICATIONREPUTATIONSERVICE \
  NS_IMETHOD QueryReputation(nsIApplicationReputationQuery *aQuery, nsIApplicationReputationCallback *aCallback); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLICATIONREPUTATIONSERVICE(_to) \
  NS_IMETHOD QueryReputation(nsIApplicationReputationQuery *aQuery, nsIApplicationReputationCallback *aCallback) { return _to QueryReputation(aQuery, aCallback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLICATIONREPUTATIONSERVICE(_to) \
  NS_IMETHOD QueryReputation(nsIApplicationReputationQuery *aQuery, nsIApplicationReputationCallback *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->QueryReputation(aQuery, aCallback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsApplicationReputationService : public nsIApplicationReputationService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLICATIONREPUTATIONSERVICE

  nsApplicationReputationService();

private:
  ~nsApplicationReputationService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsApplicationReputationService, nsIApplicationReputationService)

nsApplicationReputationService::nsApplicationReputationService()
{
  /* member initializers and constructor code */
}

nsApplicationReputationService::~nsApplicationReputationService()
{
  /* destructor code */
}

/* void queryReputation (in nsIApplicationReputationQuery aQuery, in nsIApplicationReputationCallback aCallback); */
NS_IMETHODIMP nsApplicationReputationService::QueryReputation(nsIApplicationReputationQuery *aQuery, nsIApplicationReputationCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIApplicationReputationQuery */
#define NS_IAPPLICATIONREPUTATIONQUERY_IID_STR "857da2c0-cfe5-11e2-8b8b-0800200c9a66"

#define NS_IAPPLICATIONREPUTATIONQUERY_IID \
  {0x857da2c0, 0xcfe5, 0x11e2, \
    { 0x8b, 0x8b, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIApplicationReputationQuery : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLICATIONREPUTATIONQUERY_IID)

  /* attribute nsIURI sourceURI; */
  NS_IMETHOD GetSourceURI(nsIURI * *aSourceURI) = 0;
  NS_IMETHOD SetSourceURI(nsIURI *aSourceURI) = 0;

  /* attribute AString suggestedFileName; */
  NS_IMETHOD GetSuggestedFileName(nsAString & aSuggestedFileName) = 0;
  NS_IMETHOD SetSuggestedFileName(const nsAString & aSuggestedFileName) = 0;

  /* attribute unsigned long fileSize; */
  NS_IMETHOD GetFileSize(uint32_t *aFileSize) = 0;
  NS_IMETHOD SetFileSize(uint32_t aFileSize) = 0;

  /* attribute ACString sha256Hash; */
  NS_IMETHOD GetSha256Hash(nsACString & aSha256Hash) = 0;
  NS_IMETHOD SetSha256Hash(const nsACString & aSha256Hash) = 0;

  /* attribute nsIApplicationReputationCallback callback; */
  NS_IMETHOD GetCallback(nsIApplicationReputationCallback * *aCallback) = 0;
  NS_IMETHOD SetCallback(nsIApplicationReputationCallback *aCallback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIApplicationReputationQuery, NS_IAPPLICATIONREPUTATIONQUERY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLICATIONREPUTATIONQUERY \
  NS_IMETHOD GetSourceURI(nsIURI * *aSourceURI); \
  NS_IMETHOD SetSourceURI(nsIURI *aSourceURI); \
  NS_IMETHOD GetSuggestedFileName(nsAString & aSuggestedFileName); \
  NS_IMETHOD SetSuggestedFileName(const nsAString & aSuggestedFileName); \
  NS_IMETHOD GetFileSize(uint32_t *aFileSize); \
  NS_IMETHOD SetFileSize(uint32_t aFileSize); \
  NS_IMETHOD GetSha256Hash(nsACString & aSha256Hash); \
  NS_IMETHOD SetSha256Hash(const nsACString & aSha256Hash); \
  NS_IMETHOD GetCallback(nsIApplicationReputationCallback * *aCallback); \
  NS_IMETHOD SetCallback(nsIApplicationReputationCallback *aCallback); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLICATIONREPUTATIONQUERY(_to) \
  NS_IMETHOD GetSourceURI(nsIURI * *aSourceURI) { return _to GetSourceURI(aSourceURI); } \
  NS_IMETHOD SetSourceURI(nsIURI *aSourceURI) { return _to SetSourceURI(aSourceURI); } \
  NS_IMETHOD GetSuggestedFileName(nsAString & aSuggestedFileName) { return _to GetSuggestedFileName(aSuggestedFileName); } \
  NS_IMETHOD SetSuggestedFileName(const nsAString & aSuggestedFileName) { return _to SetSuggestedFileName(aSuggestedFileName); } \
  NS_IMETHOD GetFileSize(uint32_t *aFileSize) { return _to GetFileSize(aFileSize); } \
  NS_IMETHOD SetFileSize(uint32_t aFileSize) { return _to SetFileSize(aFileSize); } \
  NS_IMETHOD GetSha256Hash(nsACString & aSha256Hash) { return _to GetSha256Hash(aSha256Hash); } \
  NS_IMETHOD SetSha256Hash(const nsACString & aSha256Hash) { return _to SetSha256Hash(aSha256Hash); } \
  NS_IMETHOD GetCallback(nsIApplicationReputationCallback * *aCallback) { return _to GetCallback(aCallback); } \
  NS_IMETHOD SetCallback(nsIApplicationReputationCallback *aCallback) { return _to SetCallback(aCallback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLICATIONREPUTATIONQUERY(_to) \
  NS_IMETHOD GetSourceURI(nsIURI * *aSourceURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceURI(aSourceURI); } \
  NS_IMETHOD SetSourceURI(nsIURI *aSourceURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSourceURI(aSourceURI); } \
  NS_IMETHOD GetSuggestedFileName(nsAString & aSuggestedFileName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSuggestedFileName(aSuggestedFileName); } \
  NS_IMETHOD SetSuggestedFileName(const nsAString & aSuggestedFileName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSuggestedFileName(aSuggestedFileName); } \
  NS_IMETHOD GetFileSize(uint32_t *aFileSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileSize(aFileSize); } \
  NS_IMETHOD SetFileSize(uint32_t aFileSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFileSize(aFileSize); } \
  NS_IMETHOD GetSha256Hash(nsACString & aSha256Hash) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSha256Hash(aSha256Hash); } \
  NS_IMETHOD SetSha256Hash(const nsACString & aSha256Hash) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSha256Hash(aSha256Hash); } \
  NS_IMETHOD GetCallback(nsIApplicationReputationCallback * *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCallback(aCallback); } \
  NS_IMETHOD SetCallback(nsIApplicationReputationCallback *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCallback(aCallback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsApplicationReputationQuery : public nsIApplicationReputationQuery
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLICATIONREPUTATIONQUERY

  nsApplicationReputationQuery();

private:
  ~nsApplicationReputationQuery();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsApplicationReputationQuery, nsIApplicationReputationQuery)

nsApplicationReputationQuery::nsApplicationReputationQuery()
{
  /* member initializers and constructor code */
}

nsApplicationReputationQuery::~nsApplicationReputationQuery()
{
  /* destructor code */
}

/* attribute nsIURI sourceURI; */
NS_IMETHODIMP nsApplicationReputationQuery::GetSourceURI(nsIURI * *aSourceURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsApplicationReputationQuery::SetSourceURI(nsIURI *aSourceURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString suggestedFileName; */
NS_IMETHODIMP nsApplicationReputationQuery::GetSuggestedFileName(nsAString & aSuggestedFileName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsApplicationReputationQuery::SetSuggestedFileName(const nsAString & aSuggestedFileName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long fileSize; */
NS_IMETHODIMP nsApplicationReputationQuery::GetFileSize(uint32_t *aFileSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsApplicationReputationQuery::SetFileSize(uint32_t aFileSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString sha256Hash; */
NS_IMETHODIMP nsApplicationReputationQuery::GetSha256Hash(nsACString & aSha256Hash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsApplicationReputationQuery::SetSha256Hash(const nsACString & aSha256Hash)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIApplicationReputationCallback callback; */
NS_IMETHODIMP nsApplicationReputationQuery::GetCallback(nsIApplicationReputationCallback * *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsApplicationReputationQuery::SetCallback(nsIApplicationReputationCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIApplicationReputationCallback */
#define NS_IAPPLICATIONREPUTATIONCALLBACK_IID_STR "9a228470-cfe5-11e2-8b8b-0800200c9a66"

#define NS_IAPPLICATIONREPUTATIONCALLBACK_IID \
  {0x9a228470, 0xcfe5, 0x11e2, \
    { 0x8b, 0x8b, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIApplicationReputationCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLICATIONREPUTATIONCALLBACK_IID)

  /* void onComplete (in bool aShouldBlock, in nsresult aStatus); */
  NS_IMETHOD OnComplete(bool aShouldBlock, nsresult aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIApplicationReputationCallback, NS_IAPPLICATIONREPUTATIONCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLICATIONREPUTATIONCALLBACK \
  NS_IMETHOD OnComplete(bool aShouldBlock, nsresult aStatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLICATIONREPUTATIONCALLBACK(_to) \
  NS_IMETHOD OnComplete(bool aShouldBlock, nsresult aStatus) { return _to OnComplete(aShouldBlock, aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLICATIONREPUTATIONCALLBACK(_to) \
  NS_IMETHOD OnComplete(bool aShouldBlock, nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnComplete(aShouldBlock, aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsApplicationReputationCallback : public nsIApplicationReputationCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLICATIONREPUTATIONCALLBACK

  nsApplicationReputationCallback();

private:
  ~nsApplicationReputationCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsApplicationReputationCallback, nsIApplicationReputationCallback)

nsApplicationReputationCallback::nsApplicationReputationCallback()
{
  /* member initializers and constructor code */
}

nsApplicationReputationCallback::~nsApplicationReputationCallback()
{
  /* destructor code */
}

/* void onComplete (in bool aShouldBlock, in nsresult aStatus); */
NS_IMETHODIMP nsApplicationReputationCallback::OnComplete(bool aShouldBlock, nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIApplicationReputation_h__ */
