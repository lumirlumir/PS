# 1. Introduction

- 백준(Baekjoon), 프로그래머스(Programmers) 등 Problem Solving(이하 PS)을 하며 생성된 소스 코드들을 효율적으로 관리하기 위해 고안된 프레임워크입니다.
- C/C++ 언어 사용자들을 대상으로 합니다.

## 1-1. Reasons for selecting VScode

### 1-1-1. PS만을 위한 가벼운 에디터(Editor)의 필요성.

- C 계열 언어의 개발이 주로 이루어지는 Visual Studio는 통합 IDE로써 프로그램이 무겁고 복잡합니다. 이를 단순 PS만을 위해 사용하기에는 부담이 따릅니다.

### 1-1-2. 라이브러리(Library)를 제외한 의존성 관계의 불필요성.

- 일반적인 개발의 경우, 다양한 파일 및 소스코드들의 의존성 관계를 관리하며 빌드(Build)를 진행합니다. 이를 C 계열 언어에서 효율적으로 수행하기 위해서는 Visual Studio가 최적이라 할 수 있습니다.
- 하지만, PS의 경우, 각각의 소스코드들이 독립적입니다. 각각의 소스코드 내부에서 사용되는 라이브러리(Library)들에는 의존적일 수 있지만, 이외의 파일에는 의존적이지 않습니다.
- 예를 들어, Visual Studio에서 C/C++ 프로젝트를 시작하게 되면, 외부종속성 및 리소스 등을 관리하기 위한 수많은 부가 파일들이 생성됩니다. 이는 단순 PS만을 위한 환경으로는 과합니다.

## 1-2. Shortcomings of VScode

### 1-2-1. 컴파일러의 부재 및 다소 복잡한 설치 과정.

- Visual Studio와는 달리, VScode에는 C/C++ Compiler가 내장되어 있지 않습니다. Extension을 통한 확장 설치도 불가능합니다. 따라서, 운영체제에 따라 컴파일러를 개별 설치해 주거나 기존에 설치되어 있는 컴파일러를 이용해야 합니다.
- 하지만, 이 과정이 다소 복잡합니다. 일반적인 방법으로 VScode에서 컴파일러를 사용하기 위해서는 tasks.json 파일을 수정하여 컴파일 및 빌드 관련 내용들을 설정해야 합니다. 생각보다 복잡한 과정에 어려움을 겪는 사람들이 많습니다.
- 따라서, 'C/C++ Compile Run'이라는 VScode Extension을 통해 일관된 방식으로 컴파일러를 설치 및 실행할 수 있게 하였습니다. 이는 기존 방식보다 쉽고 편리합니다.

### 1-2-2. 일관된 Convention(Linter or Formatter)의 필요성.

- Visual Studio의 경우 IDE에서 자동으로 Convention을 맞춰줍니다. 하지만, VScode는 단순 에디터이기 때문에 아무런 기능이 없습니다. 'C/C++ Extension Pack'이라는 VScode Extension을 설치하면 자동적으로 'clang-format'이라는 Formatter가 함께 설치됩니다. 이는 C/C++ 언어를 위한 Linter 혹은 Formatter라 할 수 있습니다. 'clang-format'을 통해 일관된 Convention을 유지할 수 있게 하였습니다.
- 또한, 'editorconfig'를 통해 보다 전역적인 Convention을 유지할 수 있게 하였습니다.

### 1-2-3. CI/CD 과정의 필요성.

- 문법 및 Convention 오류가 있는 소스코드가 업로드된다면 문제가 될 수 있습니다. 이를 Github Workflows를 통해 자동으로 관리합니다. c, cpp, h 확장자를 가진 파일을 수정 및 추가한 후 Push 및 Pull_Request를 진행할 경우, 자동으로 문법 및 Convention을 검사한 후 CI/CD 과정을 수행합니다.

### 1-2-4. IDE와 유사한 환경 구성의 필요성.

- 결국, Visual Studio의 장점과 VScode의 장점을 합치기 위해 현재 프레임워크를 설계하였습니다. Visual Studio처럼 편리하면서 가볍고 확장 가능한 VScode 개발환경을 만드는 것이 목표입니다.

# 2. How to install

## 2-1. Prerequisite

### 2-1-1. Git

- Git을 설치해야 합니다.

### 2-1-2. VScode

- VScode를 설치해야 합니다.

### 2-1-3. VScode Extension & C/C++ Compiler

- 아래 Extesion 및 Compiler를 VScode 상에 모두 설치합니다.

1. C/C++ Extension Pack

2. C/C++ Compile Run & TDM-GCC(Compiler)

   > 'C/C++ Compile Run' Extension을 설치한 후, 해당 Extension의 Manual에 따라 TDM-GCC를 설치합니다.
   >
   > C Compiler의 기본 경로
   >
   > - /usr/bin/gcc (Linux)
   > - C:\TDM-GCC-64\bin\gcc.exe (Windows)
   >
   > C++ Compiler의 기본 경로
   >
   > - /usr/bin/g++ (Linux)
   > - C:\TDM-GCC-64\bin\gcc.exe (Windows)

3. EditorConfig for VS Code

## 2-2. git clone

Git Bash 상에 아래 명령어를 입력합니다.

```bash
git clone https://github.com/lumirlumir/PS_Framework.git
```

# 3. File Structures

```bash
📦PS_Framework
 ┣ 📂.github
 ┃ ┗ 📂workflows
 ┃   ┗ 📜SyntaxCheck.yaml # Git: Github Workflows 설정 파일.
 ┣ 📂.vscode
 ┃ ┗ 📜settings.json # VScode: Editor 설정 파일.
 ┣ 📂Src
 ┃ ┗ 📂* (Baekjoon, Programmers or Etc.)
 ┃   ┣ 📂Blogged # 블로그에 게시된 문제 저장.
 ┃   ┣ 📂Solved # 다 푼 문제 저장.
 ┃   ┗ 📂Unsolved # 아직 풀고있는 문제 저장.
 ┣ 📜.clang-format # C/C++: Convention 설정 파일.
 ┣ 📜.editorconfig # EditorConfig: Covention 설정 파일.
 ┣ 📜.gitignore # Git: Gitignore 설정 파일.
 ┣ 📜README.md # Git: README 파일.
 ┗ 📜VScode.code-workspace # VScode: Workspace 설정 파일.
```

# 4. Others

## 4-1. Blog에 Repository상의 소스코드를 삽입하는 방법.

- [Emgithub](https://emgithub.com/)

# 5. Release Note

- v0.0.1: 2024.02.20
