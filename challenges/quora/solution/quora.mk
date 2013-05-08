##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=quora
ConfigurationName      :=Debug
WorkspacePath          := "E:\Varun\GitHub\learn\practice\solution"
ProjectPath            := "E:\Varun\GitHub\learn\challenges\quora\solution"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=varunkh
Date                   :=5/7/2013
CodeLitePath           :="D:\Program Files (x86)\CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="quora.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=D:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=D:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/src_main$(ObjectSuffix) $(IntermediateDirectory)/src_01_Nearby$(ObjectSuffix) $(IntermediateDirectory)/src_02_TypeAhead$(ObjectSuffix) $(IntermediateDirectory)/src_03_ScrabbleStepladder$(ObjectSuffix) $(IntermediateDirectory)/src_04_DatacenterCooling$(ObjectSuffix) $(IntermediateDirectory)/src_05_FeedOptimizer$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_main$(ObjectSuffix): ../src/main.cpp $(IntermediateDirectory)/src_main$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/challenges/quora/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main$(DependSuffix): ../src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main$(DependSuffix) -MM "../src/main.cpp"

$(IntermediateDirectory)/src_main$(PreprocessSuffix): ../src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main$(PreprocessSuffix) "../src/main.cpp"

$(IntermediateDirectory)/src_01_Nearby$(ObjectSuffix): ../src/01_Nearby.cpp $(IntermediateDirectory)/src_01_Nearby$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/challenges/quora/src/01_Nearby.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_01_Nearby$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_01_Nearby$(DependSuffix): ../src/01_Nearby.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_01_Nearby$(ObjectSuffix) -MF$(IntermediateDirectory)/src_01_Nearby$(DependSuffix) -MM "../src/01_Nearby.cpp"

$(IntermediateDirectory)/src_01_Nearby$(PreprocessSuffix): ../src/01_Nearby.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_01_Nearby$(PreprocessSuffix) "../src/01_Nearby.cpp"

$(IntermediateDirectory)/src_02_TypeAhead$(ObjectSuffix): ../src/02_TypeAhead.cpp $(IntermediateDirectory)/src_02_TypeAhead$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/challenges/quora/src/02_TypeAhead.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_02_TypeAhead$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_02_TypeAhead$(DependSuffix): ../src/02_TypeAhead.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_02_TypeAhead$(ObjectSuffix) -MF$(IntermediateDirectory)/src_02_TypeAhead$(DependSuffix) -MM "../src/02_TypeAhead.cpp"

$(IntermediateDirectory)/src_02_TypeAhead$(PreprocessSuffix): ../src/02_TypeAhead.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_02_TypeAhead$(PreprocessSuffix) "../src/02_TypeAhead.cpp"

$(IntermediateDirectory)/src_03_ScrabbleStepladder$(ObjectSuffix): ../src/03_ScrabbleStepladder.cpp $(IntermediateDirectory)/src_03_ScrabbleStepladder$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/challenges/quora/src/03_ScrabbleStepladder.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_03_ScrabbleStepladder$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_03_ScrabbleStepladder$(DependSuffix): ../src/03_ScrabbleStepladder.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_03_ScrabbleStepladder$(ObjectSuffix) -MF$(IntermediateDirectory)/src_03_ScrabbleStepladder$(DependSuffix) -MM "../src/03_ScrabbleStepladder.cpp"

$(IntermediateDirectory)/src_03_ScrabbleStepladder$(PreprocessSuffix): ../src/03_ScrabbleStepladder.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_03_ScrabbleStepladder$(PreprocessSuffix) "../src/03_ScrabbleStepladder.cpp"

$(IntermediateDirectory)/src_04_DatacenterCooling$(ObjectSuffix): ../src/04_DatacenterCooling.cpp $(IntermediateDirectory)/src_04_DatacenterCooling$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/challenges/quora/src/04_DatacenterCooling.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_04_DatacenterCooling$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_04_DatacenterCooling$(DependSuffix): ../src/04_DatacenterCooling.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_04_DatacenterCooling$(ObjectSuffix) -MF$(IntermediateDirectory)/src_04_DatacenterCooling$(DependSuffix) -MM "../src/04_DatacenterCooling.cpp"

$(IntermediateDirectory)/src_04_DatacenterCooling$(PreprocessSuffix): ../src/04_DatacenterCooling.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_04_DatacenterCooling$(PreprocessSuffix) "../src/04_DatacenterCooling.cpp"

$(IntermediateDirectory)/src_05_FeedOptimizer$(ObjectSuffix): ../src/05_FeedOptimizer.cpp $(IntermediateDirectory)/src_05_FeedOptimizer$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Varun/GitHub/learn/challenges/quora/src/05_FeedOptimizer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_05_FeedOptimizer$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_05_FeedOptimizer$(DependSuffix): ../src/05_FeedOptimizer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_05_FeedOptimizer$(ObjectSuffix) -MF$(IntermediateDirectory)/src_05_FeedOptimizer$(DependSuffix) -MM "../src/05_FeedOptimizer.cpp"

$(IntermediateDirectory)/src_05_FeedOptimizer$(PreprocessSuffix): ../src/05_FeedOptimizer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_05_FeedOptimizer$(PreprocessSuffix) "../src/05_FeedOptimizer.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/src_main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_01_Nearby$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_01_Nearby$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_01_Nearby$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_02_TypeAhead$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_02_TypeAhead$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_02_TypeAhead$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_03_ScrabbleStepladder$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_03_ScrabbleStepladder$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_03_ScrabbleStepladder$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_04_DatacenterCooling$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_04_DatacenterCooling$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_04_DatacenterCooling$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_05_FeedOptimizer$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_05_FeedOptimizer$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_05_FeedOptimizer$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../../../practice/solution/.build-debug/quora"


