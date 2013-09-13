/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/xpcom/base/nsIMemoryInfoDumper.idl
 */

#ifndef __gen_nsIMemoryInfoDumper_h__
#define __gen_nsIMemoryInfoDumper_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMemoryInfoDumper */
#define NS_IMEMORYINFODUMPER_IID_STR "3ffa5113-2a10-43bb-923b-6a2faf67be97"

#define NS_IMEMORYINFODUMPER_IID \
  {0x3ffa5113, 0x2a10, 0x43bb, \
    { 0x92, 0x3b, 0x6a, 0x2f, 0xaf, 0x67, 0xbe, 0x97 }}

class NS_NO_VTABLE nsIMemoryInfoDumper : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEMORYINFODUMPER_IID)

  /* void dumpMemoryReportsToNamedFile (in AString aFilename); */
  NS_IMETHOD DumpMemoryReportsToNamedFile(const nsAString & aFilename) = 0;

  /* void dumpMemoryInfoToTempDir (in AString aIdentifier, in bool aMinimizeMemoryUsage, in bool aDumpChildProcesses); */
  NS_IMETHOD DumpMemoryInfoToTempDir(const nsAString & aIdentifier, bool aMinimizeMemoryUsage, bool aDumpChildProcesses) = 0;

  /* void dumpGCAndCCLogsToFile (in AString aIdentifier, in bool aDumpAllTraces, in bool aDumpChildProcesses); */
  NS_IMETHOD DumpGCAndCCLogsToFile(const nsAString & aIdentifier, bool aDumpAllTraces, bool aDumpChildProcesses) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMemoryInfoDumper, NS_IMEMORYINFODUMPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEMORYINFODUMPER \
  NS_IMETHOD DumpMemoryReportsToNamedFile(const nsAString & aFilename); \
  NS_IMETHOD DumpMemoryInfoToTempDir(const nsAString & aIdentifier, bool aMinimizeMemoryUsage, bool aDumpChildProcesses); \
  NS_IMETHOD DumpGCAndCCLogsToFile(const nsAString & aIdentifier, bool aDumpAllTraces, bool aDumpChildProcesses); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEMORYINFODUMPER(_to) \
  NS_IMETHOD DumpMemoryReportsToNamedFile(const nsAString & aFilename) { return _to DumpMemoryReportsToNamedFile(aFilename); } \
  NS_IMETHOD DumpMemoryInfoToTempDir(const nsAString & aIdentifier, bool aMinimizeMemoryUsage, bool aDumpChildProcesses) { return _to DumpMemoryInfoToTempDir(aIdentifier, aMinimizeMemoryUsage, aDumpChildProcesses); } \
  NS_IMETHOD DumpGCAndCCLogsToFile(const nsAString & aIdentifier, bool aDumpAllTraces, bool aDumpChildProcesses) { return _to DumpGCAndCCLogsToFile(aIdentifier, aDumpAllTraces, aDumpChildProcesses); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEMORYINFODUMPER(_to) \
  NS_IMETHOD DumpMemoryReportsToNamedFile(const nsAString & aFilename) { return !_to ? NS_ERROR_NULL_POINTER : _to->DumpMemoryReportsToNamedFile(aFilename); } \
  NS_IMETHOD DumpMemoryInfoToTempDir(const nsAString & aIdentifier, bool aMinimizeMemoryUsage, bool aDumpChildProcesses) { return !_to ? NS_ERROR_NULL_POINTER : _to->DumpMemoryInfoToTempDir(aIdentifier, aMinimizeMemoryUsage, aDumpChildProcesses); } \
  NS_IMETHOD DumpGCAndCCLogsToFile(const nsAString & aIdentifier, bool aDumpAllTraces, bool aDumpChildProcesses) { return !_to ? NS_ERROR_NULL_POINTER : _to->DumpGCAndCCLogsToFile(aIdentifier, aDumpAllTraces, aDumpChildProcesses); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMemoryInfoDumper : public nsIMemoryInfoDumper
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMEMORYINFODUMPER

  nsMemoryInfoDumper();

private:
  ~nsMemoryInfoDumper();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMemoryInfoDumper, nsIMemoryInfoDumper)

nsMemoryInfoDumper::nsMemoryInfoDumper()
{
  /* member initializers and constructor code */
}

nsMemoryInfoDumper::~nsMemoryInfoDumper()
{
  /* destructor code */
}

/* void dumpMemoryReportsToNamedFile (in AString aFilename); */
NS_IMETHODIMP nsMemoryInfoDumper::DumpMemoryReportsToNamedFile(const nsAString & aFilename)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dumpMemoryInfoToTempDir (in AString aIdentifier, in bool aMinimizeMemoryUsage, in bool aDumpChildProcesses); */
NS_IMETHODIMP nsMemoryInfoDumper::DumpMemoryInfoToTempDir(const nsAString & aIdentifier, bool aMinimizeMemoryUsage, bool aDumpChildProcesses)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dumpGCAndCCLogsToFile (in AString aIdentifier, in bool aDumpAllTraces, in bool aDumpChildProcesses); */
NS_IMETHODIMP nsMemoryInfoDumper::DumpGCAndCCLogsToFile(const nsAString & aIdentifier, bool aDumpAllTraces, bool aDumpChildProcesses)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMemoryInfoDumper_h__ */
