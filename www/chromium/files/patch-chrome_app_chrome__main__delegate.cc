--- chrome/app/chrome_main_delegate.cc.orig	2020-05-13 18:40:17 UTC
+++ chrome/app/chrome_main_delegate.cc
@@ -102,7 +102,7 @@
 #include "chrome/app/shutdown_signal_handlers_posix.h"
 #endif
 
-#if BUILDFLAG(ENABLE_NACL) && defined(OS_LINUX)
+#if BUILDFLAG(ENABLE_NACL) && defined(OS_LINUX) && !defined(OS_BSD)
 #include "components/nacl/common/nacl_paths.h"
 #include "components/nacl/zygote/nacl_fork_delegate_linux.h"
 #endif
@@ -145,12 +145,12 @@
 #include "v8/include/v8.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
 #endif
 
 #if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_ANDROID) || \
-    defined(OS_LINUX)
+    defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/policy/policy_path_parser.h"
 #include "components/crash/core/app/crashpad.h"
 #endif
@@ -276,7 +276,7 @@ void SetUpExtendedCrashReporting(bool is_browser_proce
 
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
 void AdjustLinuxOOMScore(const std::string& process_type) {
   int score = -1;
 
@@ -316,13 +316,13 @@ void AdjustLinuxOOMScore(const std::string& process_ty
   if (score > -1)
     base::AdjustOOMScore(base::GetCurrentProcId(), score);
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) && !defined(OS_BSD)
 
 // Returns true if this subprocess type needs the ResourceBundle initialized
 // and resources loaded.
 bool SubprocessNeedsResourceBundle(const std::string& process_type) {
   return
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // The zygote process opens the resources for the renderers.
       process_type == service_manager::switches::kZygoteProcess ||
 #endif
@@ -361,7 +361,7 @@ bool HandleVersionSwitches(const base::CommandLine& co
   return false;
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Show the man page if --help or -h is on the command line.
 void HandleHelpSwitches(const base::CommandLine& command_line) {
   if (command_line.HasSwitch(switches::kHelp) ||
@@ -371,7 +371,7 @@ void HandleHelpSwitches(const base::CommandLine& comma
     PLOG(FATAL) << "execlp failed";
   }
 }
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 #if !defined(OS_MACOSX) && !defined(OS_ANDROID)
 void SIGTERMProfilingShutdown(int signal) {
@@ -425,7 +425,7 @@ void InitializeUserDataDir(base::CommandLine* command_
   std::string process_type =
       command_line->GetSwitchValueASCII(switches::kProcessType);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, Chrome does not support running multiple copies under different
   // DISPLAYs, so the profile directory can be specified in the environment to
   // support the virtual desktop use-case.
@@ -437,7 +437,7 @@ void InitializeUserDataDir(base::CommandLine* command_
       user_data_dir = base::FilePath::FromUTF8Unsafe(user_data_dir_string);
     }
   }
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_BSD
 #if defined(OS_MACOSX)
   policy::path_parser::CheckUserDataDirPolicy(&user_data_dir);
 #endif  // OS_MAC
@@ -509,7 +509,7 @@ void RecordMainStartupMetrics(base::TimeTicks applicat
   startup_metric_utils::RecordApplicationStartTime(now);
 #endif
 
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   // Record the startup process creation time on supported platforms.
   startup_metric_utils::RecordStartupProcessCreationTime(
       base::Process::Current().CreationTime());
@@ -701,7 +701,7 @@ bool ChromeMainDelegate::BasicStartupComplete(int* exi
   v8_crashpad_support::SetUp();
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
   if (!crash_reporter::IsCrashpadEnabled()) {
     breakpad::SetFirstChanceExceptionHandler(v8::TryHandleWebAssemblyTrapPosix);
   }
@@ -712,7 +712,7 @@ bool ChromeMainDelegate::BasicStartupComplete(int* exi
     *exit_code = 0;
     return true;  // Got a --version switch; exit with a success error code.
   }
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // This will directly exit if the user asked for help.
   HandleHelpSwitches(command_line);
 #endif
@@ -736,7 +736,7 @@ bool ChromeMainDelegate::BasicStartupComplete(int* exi
 #if defined(OS_CHROMEOS)
   chromeos::RegisterPathProvider();
 #endif
-#if BUILDFLAG(ENABLE_NACL) && defined(OS_LINUX)
+#if BUILDFLAG(ENABLE_NACL) && defined(OS_LINUX) && !defined(OS_BSD)
   nacl::RegisterPathProvider();
 #endif
 
@@ -916,7 +916,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
 
   crash_reporter::InitializeCrashKeys();
 
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
   ChromeCrashReporterClient::Create();
 #endif
 
@@ -928,7 +928,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
 #if defined(OS_WIN)
   child_process_logging::Init();
 #endif
-#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX))
+#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD))
   // Create an instance of the CPU class to parse /proc/cpuinfo and cache
   // cpu_brand info.
   base::CPU cpu_info;
@@ -1047,7 +1047,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
         locale;
   }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   // Zygote needs to call InitCrashReporter() in RunZygote().
   if (process_type != service_manager::switches::kZygoteProcess) {
 #if defined(OS_ANDROID)
@@ -1068,7 +1068,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
     }
 #endif  // defined(OS_ANDROID)
   }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
   // After all the platform Breakpads have been initialized, store the command
   // line for crash reporting.
@@ -1082,7 +1082,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
 void ChromeMainDelegate::SandboxInitialized(const std::string& process_type) {
   // Note: If you are adding a new process type below, be sure to adjust the
   // AdjustLinuxOOMScore function too.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
   AdjustLinuxOOMScore(process_type);
 #endif
 #if defined(OS_WIN)
@@ -1128,7 +1128,7 @@ int ChromeMainDelegate::RunProcess(
     // This entry is not needed on Linux, where the NaCl loader
     // process is launched via nacl_helper instead.
 #if BUILDFLAG(ENABLE_NACL) && !defined(CHROME_MULTIPLE_DLL_BROWSER) && \
-    !defined(OS_LINUX)
+    !defined(OS_LINUX) && !defined(OS_BSD)
     {switches::kNaClLoaderProcess, NaClMain},
 #else
     {"<invalid>", NULL},  // To avoid constant array of size 0
@@ -1156,7 +1156,7 @@ void ChromeMainDelegate::ProcessExiting(const std::str
 #endif  // !defined(OS_ANDROID)
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
 void ChromeMainDelegate::ZygoteStarting(
     std::vector<std::unique_ptr<service_manager::ZygoteForkDelegate>>*
         delegates) {
@@ -1194,7 +1194,7 @@ void ChromeMainDelegate::ZygoteForked() {
   crash_keys::SetCrashKeysFromCommandLine(*command_line);
 }
 
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) && !defined(OS_BSD)
 
 content::ContentClient* ChromeMainDelegate::CreateContentClient() {
   return &chrome_content_client_;
