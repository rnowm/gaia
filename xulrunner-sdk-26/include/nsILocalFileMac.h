/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/xpcom/io/nsILocalFileMac.idl
 */

#ifndef __gen_nsILocalFileMac_h__
#define __gen_nsILocalFileMac_h__


#ifndef __gen_nsILocalFile_h__
#include "nsILocalFile.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include <Carbon/Carbon.h>
#include <CoreFoundation/CoreFoundation.h>

/* starting interface:    nsILocalFileMac */
#define NS_ILOCALFILEMAC_IID_STR "e5de2cc9-bf06-4329-8f91-5d2d45284500"

#define NS_ILOCALFILEMAC_IID \
  {0xe5de2cc9, 0xbf06, 0x4329, \
    { 0x8f, 0x91, 0x5d, 0x2d, 0x45, 0x28, 0x45, 0x00 }}

class NS_NO_VTABLE nsILocalFileMac : public nsILocalFile {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOCALFILEMAC_IID)

  /* [noscript] void initWithCFURL (in CFURLRef aCFURL); */
  NS_IMETHOD InitWithCFURL(CFURLRef aCFURL) = 0;

  /* [noscript] void initWithFSRef ([const] in FSRefPtr aFSRef); */
  NS_IMETHOD InitWithFSRef(const FSRef *aFSRef) = 0;

  /* [noscript] CFURLRef getCFURL (); */
  NS_IMETHOD GetCFURL(CFURLRef *_retval) = 0;

  /* [noscript] FSRef getFSRef (); */
  NS_IMETHOD GetFSRef(FSRef *_retval) = 0;

  /* [noscript] FSSpec getFSSpec (); */
  NS_IMETHOD GetFSSpec(FSSpec *_retval) = 0;

  /* readonly attribute int64_t fileSizeWithResFork; */
  NS_IMETHOD GetFileSizeWithResFork(int64_t *aFileSizeWithResFork) = 0;

  /* [noscript] attribute OSType fileType; */
  NS_IMETHOD GetFileType(OSType *aFileType) = 0;
  NS_IMETHOD SetFileType(OSType aFileType) = 0;

  /* [noscript] attribute OSType fileCreator; */
  NS_IMETHOD GetFileCreator(OSType *aFileCreator) = 0;
  NS_IMETHOD SetFileCreator(OSType aFileCreator) = 0;

  /* void launchWithDoc (in nsIFile aDocToLoad, in boolean aLaunchInBackground); */
  NS_IMETHOD LaunchWithDoc(nsIFile *aDocToLoad, bool aLaunchInBackground) = 0;

  /* void openDocWithApp (in nsIFile aAppToOpenWith, in boolean aLaunchInBackground); */
  NS_IMETHOD OpenDocWithApp(nsIFile *aAppToOpenWith, bool aLaunchInBackground) = 0;

  /* boolean isPackage (); */
  NS_IMETHOD IsPackage(bool *_retval) = 0;

  /* readonly attribute AString bundleDisplayName; */
  NS_IMETHOD GetBundleDisplayName(nsAString & aBundleDisplayName) = 0;

  /* readonly attribute AUTF8String bundleIdentifier; */
  NS_IMETHOD GetBundleIdentifier(nsACString & aBundleIdentifier) = 0;

  /* readonly attribute int64_t bundleContentsLastModifiedTime; */
  NS_IMETHOD GetBundleContentsLastModifiedTime(int64_t *aBundleContentsLastModifiedTime) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILocalFileMac, NS_ILOCALFILEMAC_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOCALFILEMAC \
  NS_IMETHOD InitWithCFURL(CFURLRef aCFURL); \
  NS_IMETHOD InitWithFSRef(const FSRef *aFSRef); \
  NS_IMETHOD GetCFURL(CFURLRef *_retval); \
  NS_IMETHOD GetFSRef(FSRef *_retval); \
  NS_IMETHOD GetFSSpec(FSSpec *_retval); \
  NS_IMETHOD GetFileSizeWithResFork(int64_t *aFileSizeWithResFork); \
  NS_IMETHOD GetFileType(OSType *aFileType); \
  NS_IMETHOD SetFileType(OSType aFileType); \
  NS_IMETHOD GetFileCreator(OSType *aFileCreator); \
  NS_IMETHOD SetFileCreator(OSType aFileCreator); \
  NS_IMETHOD LaunchWithDoc(nsIFile *aDocToLoad, bool aLaunchInBackground); \
  NS_IMETHOD OpenDocWithApp(nsIFile *aAppToOpenWith, bool aLaunchInBackground); \
  NS_IMETHOD IsPackage(bool *_retval); \
  NS_IMETHOD GetBundleDisplayName(nsAString & aBundleDisplayName); \
  NS_IMETHOD GetBundleIdentifier(nsACString & aBundleIdentifier); \
  NS_IMETHOD GetBundleContentsLastModifiedTime(int64_t *aBundleContentsLastModifiedTime); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOCALFILEMAC(_to) \
  NS_IMETHOD InitWithCFURL(CFURLRef aCFURL) { return _to InitWithCFURL(aCFURL); } \
  NS_IMETHOD InitWithFSRef(const FSRef *aFSRef) { return _to InitWithFSRef(aFSRef); } \
  NS_IMETHOD GetCFURL(CFURLRef *_retval) { return _to GetCFURL(_retval); } \
  NS_IMETHOD GetFSRef(FSRef *_retval) { return _to GetFSRef(_retval); } \
  NS_IMETHOD GetFSSpec(FSSpec *_retval) { return _to GetFSSpec(_retval); } \
  NS_IMETHOD GetFileSizeWithResFork(int64_t *aFileSizeWithResFork) { return _to GetFileSizeWithResFork(aFileSizeWithResFork); } \
  NS_IMETHOD GetFileType(OSType *aFileType) { return _to GetFileType(aFileType); } \
  NS_IMETHOD SetFileType(OSType aFileType) { return _to SetFileType(aFileType); } \
  NS_IMETHOD GetFileCreator(OSType *aFileCreator) { return _to GetFileCreator(aFileCreator); } \
  NS_IMETHOD SetFileCreator(OSType aFileCreator) { return _to SetFileCreator(aFileCreator); } \
  NS_IMETHOD LaunchWithDoc(nsIFile *aDocToLoad, bool aLaunchInBackground) { return _to LaunchWithDoc(aDocToLoad, aLaunchInBackground); } \
  NS_IMETHOD OpenDocWithApp(nsIFile *aAppToOpenWith, bool aLaunchInBackground) { return _to OpenDocWithApp(aAppToOpenWith, aLaunchInBackground); } \
  NS_IMETHOD IsPackage(bool *_retval) { return _to IsPackage(_retval); } \
  NS_IMETHOD GetBundleDisplayName(nsAString & aBundleDisplayName) { return _to GetBundleDisplayName(aBundleDisplayName); } \
  NS_IMETHOD GetBundleIdentifier(nsACString & aBundleIdentifier) { return _to GetBundleIdentifier(aBundleIdentifier); } \
  NS_IMETHOD GetBundleContentsLastModifiedTime(int64_t *aBundleContentsLastModifiedTime) { return _to GetBundleContentsLastModifiedTime(aBundleContentsLastModifiedTime); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOCALFILEMAC(_to) \
  NS_IMETHOD InitWithCFURL(CFURLRef aCFURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithCFURL(aCFURL); } \
  NS_IMETHOD InitWithFSRef(const FSRef *aFSRef) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithFSRef(aFSRef); } \
  NS_IMETHOD GetCFURL(CFURLRef *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCFURL(_retval); } \
  NS_IMETHOD GetFSRef(FSRef *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFSRef(_retval); } \
  NS_IMETHOD GetFSSpec(FSSpec *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFSSpec(_retval); } \
  NS_IMETHOD GetFileSizeWithResFork(int64_t *aFileSizeWithResFork) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileSizeWithResFork(aFileSizeWithResFork); } \
  NS_IMETHOD GetFileType(OSType *aFileType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileType(aFileType); } \
  NS_IMETHOD SetFileType(OSType aFileType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFileType(aFileType); } \
  NS_IMETHOD GetFileCreator(OSType *aFileCreator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileCreator(aFileCreator); } \
  NS_IMETHOD SetFileCreator(OSType aFileCreator) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFileCreator(aFileCreator); } \
  NS_IMETHOD LaunchWithDoc(nsIFile *aDocToLoad, bool aLaunchInBackground) { return !_to ? NS_ERROR_NULL_POINTER : _to->LaunchWithDoc(aDocToLoad, aLaunchInBackground); } \
  NS_IMETHOD OpenDocWithApp(nsIFile *aAppToOpenWith, bool aLaunchInBackground) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenDocWithApp(aAppToOpenWith, aLaunchInBackground); } \
  NS_IMETHOD IsPackage(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsPackage(_retval); } \
  NS_IMETHOD GetBundleDisplayName(nsAString & aBundleDisplayName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBundleDisplayName(aBundleDisplayName); } \
  NS_IMETHOD GetBundleIdentifier(nsACString & aBundleIdentifier) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBundleIdentifier(aBundleIdentifier); } \
  NS_IMETHOD GetBundleContentsLastModifiedTime(int64_t *aBundleContentsLastModifiedTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBundleContentsLastModifiedTime(aBundleContentsLastModifiedTime); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLocalFileMac : public nsILocalFileMac
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOCALFILEMAC

  nsLocalFileMac();

private:
  ~nsLocalFileMac();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLocalFileMac, nsILocalFileMac)

nsLocalFileMac::nsLocalFileMac()
{
  /* member initializers and constructor code */
}

nsLocalFileMac::~nsLocalFileMac()
{
  /* destructor code */
}

/* [noscript] void initWithCFURL (in CFURLRef aCFURL); */
NS_IMETHODIMP nsLocalFileMac::InitWithCFURL(CFURLRef aCFURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initWithFSRef ([const] in FSRefPtr aFSRef); */
NS_IMETHODIMP nsLocalFileMac::InitWithFSRef(const FSRef *aFSRef)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] CFURLRef getCFURL (); */
NS_IMETHODIMP nsLocalFileMac::GetCFURL(CFURLRef *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] FSRef getFSRef (); */
NS_IMETHODIMP nsLocalFileMac::GetFSRef(FSRef *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] FSSpec getFSSpec (); */
NS_IMETHODIMP nsLocalFileMac::GetFSSpec(FSSpec *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t fileSizeWithResFork; */
NS_IMETHODIMP nsLocalFileMac::GetFileSizeWithResFork(int64_t *aFileSizeWithResFork)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute OSType fileType; */
NS_IMETHODIMP nsLocalFileMac::GetFileType(OSType *aFileType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLocalFileMac::SetFileType(OSType aFileType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute OSType fileCreator; */
NS_IMETHODIMP nsLocalFileMac::GetFileCreator(OSType *aFileCreator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLocalFileMac::SetFileCreator(OSType aFileCreator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void launchWithDoc (in nsIFile aDocToLoad, in boolean aLaunchInBackground); */
NS_IMETHODIMP nsLocalFileMac::LaunchWithDoc(nsIFile *aDocToLoad, bool aLaunchInBackground)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void openDocWithApp (in nsIFile aAppToOpenWith, in boolean aLaunchInBackground); */
NS_IMETHODIMP nsLocalFileMac::OpenDocWithApp(nsIFile *aAppToOpenWith, bool aLaunchInBackground)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isPackage (); */
NS_IMETHODIMP nsLocalFileMac::IsPackage(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString bundleDisplayName; */
NS_IMETHODIMP nsLocalFileMac::GetBundleDisplayName(nsAString & aBundleDisplayName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String bundleIdentifier; */
NS_IMETHODIMP nsLocalFileMac::GetBundleIdentifier(nsACString & aBundleIdentifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t bundleContentsLastModifiedTime; */
NS_IMETHODIMP nsLocalFileMac::GetBundleContentsLastModifiedTime(int64_t *aBundleContentsLastModifiedTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

extern "C"
{
NS_EXPORT nsresult NS_NewLocalFileWithFSRef(const FSRef* aFSRef, bool aFollowSymlinks, nsILocalFileMac** result);
NS_EXPORT nsresult NS_NewLocalFileWithCFURL(const CFURLRef aURL, bool aFollowSymlinks, nsILocalFileMac** result);
}

#endif /* __gen_nsILocalFileMac_h__ */
