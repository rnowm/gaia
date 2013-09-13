/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/tools/profiler/nsIProfiler.idl
 */

#ifndef __gen_nsIProfiler_h__
#define __gen_nsIProfiler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIProfiler */
#define NS_IPROFILER_IID_STR "eb77a9b0-285f-472c-93b0-04db5e9e3e7e"

#define NS_IPROFILER_IID \
  {0xeb77a9b0, 0x285f, 0x472c, \
    { 0x93, 0xb0, 0x04, 0xdb, 0x5e, 0x9e, 0x3e, 0x7e }}

class NS_NO_VTABLE nsIProfiler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROFILER_IID)

  /* void StartProfiler (in uint32_t aEntries, in uint32_t aInterval, [array, size_is (aFeatureCount)] in string aFeatures, in uint32_t aFeatureCount, [array, size_is (aFilterCount), optional] in string aThreadNameFilters, [optional] in uint32_t aFilterCount); */
  NS_IMETHOD StartProfiler(uint32_t aEntries, uint32_t aInterval, const char * *aFeatures, uint32_t aFeatureCount, const char * *aThreadNameFilters, uint32_t aFilterCount) = 0;

  /* void StopProfiler (); */
  NS_IMETHOD StopProfiler(void) = 0;

  /* void AddMarker (in string aMarker); */
  NS_IMETHOD AddMarker(const char * aMarker) = 0;

  /* string GetProfile (); */
  NS_IMETHOD GetProfile(char * *_retval) = 0;

  /* [implicit_jscontext] jsval getProfileData (); */
  NS_IMETHOD GetProfileData(JSContext* cx, JS::Value *_retval) = 0;

  /* boolean IsActive (); */
  NS_IMETHOD IsActive(bool *_retval) = 0;

  /* void GetResponsivenessTimes (out uint32_t aCount, [array, size_is (aCount), retval] out double aResult); */
  NS_IMETHOD GetResponsivenessTimes(uint32_t *aCount, double **aResult) = 0;

  /* void GetFeatures (out uint32_t aCount, [array, size_is (aCount), retval] out string aFeatures); */
  NS_IMETHOD GetFeatures(uint32_t *aCount, char * **aFeatures) = 0;

  /* AString getSharedLibraryInformation (); */
  NS_IMETHOD GetSharedLibraryInformation(nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProfiler, NS_IPROFILER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROFILER \
  NS_IMETHOD StartProfiler(uint32_t aEntries, uint32_t aInterval, const char * *aFeatures, uint32_t aFeatureCount, const char * *aThreadNameFilters, uint32_t aFilterCount); \
  NS_IMETHOD StopProfiler(void); \
  NS_IMETHOD AddMarker(const char * aMarker); \
  NS_IMETHOD GetProfile(char * *_retval); \
  NS_IMETHOD GetProfileData(JSContext* cx, JS::Value *_retval); \
  NS_IMETHOD IsActive(bool *_retval); \
  NS_IMETHOD GetResponsivenessTimes(uint32_t *aCount, double **aResult); \
  NS_IMETHOD GetFeatures(uint32_t *aCount, char * **aFeatures); \
  NS_IMETHOD GetSharedLibraryInformation(nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROFILER(_to) \
  NS_IMETHOD StartProfiler(uint32_t aEntries, uint32_t aInterval, const char * *aFeatures, uint32_t aFeatureCount, const char * *aThreadNameFilters, uint32_t aFilterCount) { return _to StartProfiler(aEntries, aInterval, aFeatures, aFeatureCount, aThreadNameFilters, aFilterCount); } \
  NS_IMETHOD StopProfiler(void) { return _to StopProfiler(); } \
  NS_IMETHOD AddMarker(const char * aMarker) { return _to AddMarker(aMarker); } \
  NS_IMETHOD GetProfile(char * *_retval) { return _to GetProfile(_retval); } \
  NS_IMETHOD GetProfileData(JSContext* cx, JS::Value *_retval) { return _to GetProfileData(cx, _retval); } \
  NS_IMETHOD IsActive(bool *_retval) { return _to IsActive(_retval); } \
  NS_IMETHOD GetResponsivenessTimes(uint32_t *aCount, double **aResult) { return _to GetResponsivenessTimes(aCount, aResult); } \
  NS_IMETHOD GetFeatures(uint32_t *aCount, char * **aFeatures) { return _to GetFeatures(aCount, aFeatures); } \
  NS_IMETHOD GetSharedLibraryInformation(nsAString & _retval) { return _to GetSharedLibraryInformation(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROFILER(_to) \
  NS_IMETHOD StartProfiler(uint32_t aEntries, uint32_t aInterval, const char * *aFeatures, uint32_t aFeatureCount, const char * *aThreadNameFilters, uint32_t aFilterCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartProfiler(aEntries, aInterval, aFeatures, aFeatureCount, aThreadNameFilters, aFilterCount); } \
  NS_IMETHOD StopProfiler(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopProfiler(); } \
  NS_IMETHOD AddMarker(const char * aMarker) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddMarker(aMarker); } \
  NS_IMETHOD GetProfile(char * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProfile(_retval); } \
  NS_IMETHOD GetProfileData(JSContext* cx, JS::Value *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProfileData(cx, _retval); } \
  NS_IMETHOD IsActive(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsActive(_retval); } \
  NS_IMETHOD GetResponsivenessTimes(uint32_t *aCount, double **aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponsivenessTimes(aCount, aResult); } \
  NS_IMETHOD GetFeatures(uint32_t *aCount, char * **aFeatures) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFeatures(aCount, aFeatures); } \
  NS_IMETHOD GetSharedLibraryInformation(nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSharedLibraryInformation(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProfiler : public nsIProfiler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROFILER

  nsProfiler();

private:
  ~nsProfiler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProfiler, nsIProfiler)

nsProfiler::nsProfiler()
{
  /* member initializers and constructor code */
}

nsProfiler::~nsProfiler()
{
  /* destructor code */
}

/* void StartProfiler (in uint32_t aEntries, in uint32_t aInterval, [array, size_is (aFeatureCount)] in string aFeatures, in uint32_t aFeatureCount, [array, size_is (aFilterCount), optional] in string aThreadNameFilters, [optional] in uint32_t aFilterCount); */
NS_IMETHODIMP nsProfiler::StartProfiler(uint32_t aEntries, uint32_t aInterval, const char * *aFeatures, uint32_t aFeatureCount, const char * *aThreadNameFilters, uint32_t aFilterCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void StopProfiler (); */
NS_IMETHODIMP nsProfiler::StopProfiler()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void AddMarker (in string aMarker); */
NS_IMETHODIMP nsProfiler::AddMarker(const char * aMarker)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string GetProfile (); */
NS_IMETHODIMP nsProfiler::GetProfile(char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getProfileData (); */
NS_IMETHODIMP nsProfiler::GetProfileData(JSContext* cx, JS::Value *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean IsActive (); */
NS_IMETHODIMP nsProfiler::IsActive(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetResponsivenessTimes (out uint32_t aCount, [array, size_is (aCount), retval] out double aResult); */
NS_IMETHODIMP nsProfiler::GetResponsivenessTimes(uint32_t *aCount, double **aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void GetFeatures (out uint32_t aCount, [array, size_is (aCount), retval] out string aFeatures); */
NS_IMETHODIMP nsProfiler::GetFeatures(uint32_t *aCount, char * **aFeatures)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getSharedLibraryInformation (); */
NS_IMETHODIMP nsProfiler::GetSharedLibraryInformation(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProfiler_h__ */
