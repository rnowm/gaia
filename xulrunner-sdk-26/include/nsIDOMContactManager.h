/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/dom/interfaces/contacts/nsIDOMContactManager.idl
 */

#ifndef __gen_nsIDOMContactManager_h__
#define __gen_nsIDOMContactManager_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIContactProperties_h__
#include "nsIContactProperties.h"
#endif

#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIDOMDOMRequest; /* forward declaration */

class nsIDOMDOMCursor; /* forward declaration */


/* starting interface:    nsIDOMContact */
#define NS_IDOMCONTACT_IID_STR "72a5ee28-81d8-4af8-90b3-ae935396cc66"

#define NS_IDOMCONTACT_IID \
  {0x72a5ee28, 0x81d8, 0x4af8, \
    { 0x90, 0xb3, 0xae, 0x93, 0x53, 0x96, 0xcc, 0x66 }}

class NS_NO_VTABLE nsIDOMContact : public nsIContactProperties {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCONTACT_IID)

  /* attribute DOMString id; */
  NS_IMETHOD GetId(nsAString & aId) = 0;
  NS_IMETHOD SetId(const nsAString & aId) = 0;

  /* readonly attribute jsval published; */
  NS_IMETHOD GetPublished(JS::Value *aPublished) = 0;

  /* readonly attribute jsval updated; */
  NS_IMETHOD GetUpdated(JS::Value *aUpdated) = 0;

  /* void init (in nsIContactProperties properties); */
  NS_IMETHOD Init(nsIContactProperties *properties) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMContact, NS_IDOMCONTACT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCONTACT \
  NS_IMETHOD GetId(nsAString & aId); \
  NS_IMETHOD SetId(const nsAString & aId); \
  NS_IMETHOD GetPublished(JS::Value *aPublished); \
  NS_IMETHOD GetUpdated(JS::Value *aUpdated); \
  NS_IMETHOD Init(nsIContactProperties *properties); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCONTACT(_to) \
  NS_IMETHOD GetId(nsAString & aId) { return _to GetId(aId); } \
  NS_IMETHOD SetId(const nsAString & aId) { return _to SetId(aId); } \
  NS_IMETHOD GetPublished(JS::Value *aPublished) { return _to GetPublished(aPublished); } \
  NS_IMETHOD GetUpdated(JS::Value *aUpdated) { return _to GetUpdated(aUpdated); } \
  NS_IMETHOD Init(nsIContactProperties *properties) { return _to Init(properties); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCONTACT(_to) \
  NS_IMETHOD GetId(nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD SetId(const nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetId(aId); } \
  NS_IMETHOD GetPublished(JS::Value *aPublished) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPublished(aPublished); } \
  NS_IMETHOD GetUpdated(JS::Value *aUpdated) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpdated(aUpdated); } \
  NS_IMETHOD Init(nsIContactProperties *properties) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(properties); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMContact : public nsIDOMContact
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCONTACT

  nsDOMContact();

private:
  ~nsDOMContact();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMContact, nsIDOMContact)

nsDOMContact::nsDOMContact()
{
  /* member initializers and constructor code */
}

nsDOMContact::~nsDOMContact()
{
  /* destructor code */
}

/* attribute DOMString id; */
NS_IMETHODIMP nsDOMContact::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMContact::SetId(const nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval published; */
NS_IMETHODIMP nsDOMContact::GetPublished(JS::Value *aPublished)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval updated; */
NS_IMETHODIMP nsDOMContact::GetUpdated(JS::Value *aUpdated)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (in nsIContactProperties properties); */
NS_IMETHODIMP nsDOMContact::Init(nsIContactProperties *properties)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMContactManager */
#define NS_IDOMCONTACTMANAGER_IID_STR "8beb3a66-d70a-4111-b216-b8e995ad3aff"

#define NS_IDOMCONTACTMANAGER_IID \
  {0x8beb3a66, 0xd70a, 0x4111, \
    { 0xb2, 0x16, 0xb8, 0xe9, 0x95, 0xad, 0x3a, 0xff }}

class NS_NO_VTABLE nsIDOMContactManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCONTACTMANAGER_IID)

  /* nsIDOMDOMRequest find (in nsIContactFindOptions options); */
  NS_IMETHOD Find(nsIContactFindOptions *options, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMCursor getAll (in nsIContactFindSortOptions options); */
  NS_IMETHOD GetAll(nsIContactFindSortOptions *options, nsIDOMDOMCursor * *_retval) = 0;

  /* nsIDOMDOMRequest clear (); */
  NS_IMETHOD Clear(nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest save (in nsIDOMContact contact); */
  NS_IMETHOD Save(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest remove (in nsIDOMContact contact); */
  NS_IMETHOD Remove(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval) = 0;

  /* attribute nsIDOMEventListener oncontactchange; */
  NS_IMETHOD GetOncontactchange(nsIDOMEventListener * *aOncontactchange) = 0;
  NS_IMETHOD SetOncontactchange(nsIDOMEventListener *aOncontactchange) = 0;

  /* nsIDOMDOMRequest getRevision (); */
  NS_IMETHOD GetRevision(nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest getCount (); */
  NS_IMETHOD GetCount(nsIDOMDOMRequest * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMContactManager, NS_IDOMCONTACTMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCONTACTMANAGER \
  NS_IMETHOD Find(nsIContactFindOptions *options, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetAll(nsIContactFindSortOptions *options, nsIDOMDOMCursor * *_retval); \
  NS_IMETHOD Clear(nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Save(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Remove(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetOncontactchange(nsIDOMEventListener * *aOncontactchange); \
  NS_IMETHOD SetOncontactchange(nsIDOMEventListener *aOncontactchange); \
  NS_IMETHOD GetRevision(nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetCount(nsIDOMDOMRequest * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCONTACTMANAGER(_to) \
  NS_IMETHOD Find(nsIContactFindOptions *options, nsIDOMDOMRequest * *_retval) { return _to Find(options, _retval); } \
  NS_IMETHOD GetAll(nsIContactFindSortOptions *options, nsIDOMDOMCursor * *_retval) { return _to GetAll(options, _retval); } \
  NS_IMETHOD Clear(nsIDOMDOMRequest * *_retval) { return _to Clear(_retval); } \
  NS_IMETHOD Save(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval) { return _to Save(contact, _retval); } \
  NS_IMETHOD Remove(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval) { return _to Remove(contact, _retval); } \
  NS_IMETHOD GetOncontactchange(nsIDOMEventListener * *aOncontactchange) { return _to GetOncontactchange(aOncontactchange); } \
  NS_IMETHOD SetOncontactchange(nsIDOMEventListener *aOncontactchange) { return _to SetOncontactchange(aOncontactchange); } \
  NS_IMETHOD GetRevision(nsIDOMDOMRequest * *_retval) { return _to GetRevision(_retval); } \
  NS_IMETHOD GetCount(nsIDOMDOMRequest * *_retval) { return _to GetCount(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCONTACTMANAGER(_to) \
  NS_IMETHOD Find(nsIContactFindOptions *options, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Find(options, _retval); } \
  NS_IMETHOD GetAll(nsIContactFindSortOptions *options, nsIDOMDOMCursor * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAll(options, _retval); } \
  NS_IMETHOD Clear(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Clear(_retval); } \
  NS_IMETHOD Save(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Save(contact, _retval); } \
  NS_IMETHOD Remove(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(contact, _retval); } \
  NS_IMETHOD GetOncontactchange(nsIDOMEventListener * *aOncontactchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOncontactchange(aOncontactchange); } \
  NS_IMETHOD SetOncontactchange(nsIDOMEventListener *aOncontactchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOncontactchange(aOncontactchange); } \
  NS_IMETHOD GetRevision(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRevision(_retval); } \
  NS_IMETHOD GetCount(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCount(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMContactManager : public nsIDOMContactManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCONTACTMANAGER

  nsDOMContactManager();

private:
  ~nsDOMContactManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMContactManager, nsIDOMContactManager)

nsDOMContactManager::nsDOMContactManager()
{
  /* member initializers and constructor code */
}

nsDOMContactManager::~nsDOMContactManager()
{
  /* destructor code */
}

/* nsIDOMDOMRequest find (in nsIContactFindOptions options); */
NS_IMETHODIMP nsDOMContactManager::Find(nsIContactFindOptions *options, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMCursor getAll (in nsIContactFindSortOptions options); */
NS_IMETHODIMP nsDOMContactManager::GetAll(nsIContactFindSortOptions *options, nsIDOMDOMCursor * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest clear (); */
NS_IMETHODIMP nsDOMContactManager::Clear(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest save (in nsIDOMContact contact); */
NS_IMETHODIMP nsDOMContactManager::Save(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest remove (in nsIDOMContact contact); */
NS_IMETHODIMP nsDOMContactManager::Remove(nsIDOMContact *contact, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener oncontactchange; */
NS_IMETHODIMP nsDOMContactManager::GetOncontactchange(nsIDOMEventListener * *aOncontactchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMContactManager::SetOncontactchange(nsIDOMEventListener *aOncontactchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest getRevision (); */
NS_IMETHODIMP nsDOMContactManager::GetRevision(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest getCount (); */
NS_IMETHODIMP nsDOMContactManager::GetCount(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMContactManager_h__ */
