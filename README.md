# hello-github

안녕하세요! 저의 첫 번째 GitHub 프로젝트입니다.

브랜치에서 작업 중입니다.

# GitHub 사용방법 정리(개인)
1. new repository
    Add README [on] 
2. Clone
    git clone https://github.com/hyeonho613/hello-github.git
3. Edit
    ... (edit) ...
    git add README.md
    git commit -m "Add modifications"
4. Push
    git push

# GitHub 사용방법 정리(협업)
1. Fork
    other github -> my github
2. Clone 
    my github -> local PC
3. Edit 
    git checkout -b update-readme (create new branch)
    ... (edit) ...
    git add README.md
    git commit -m "Add modifications"
4. Push 
    local PC -> my github
    git push origin update-readme (origin = my gitgub, update-readme = my branch)
5. PR
    my github -> other github
6. Merge(other)
    update-readme branch -> main branch


---

## ✨ GitHub 워크플로우 요약

이 문서는 기본적인 GitHub 사용법을 개인 작업 흐름과 협업 흐름으로 나누어 요약한 것입니다.

### 👤 개인 작업 흐름 (Solo Workflow)

혼자서 프로젝트를 진행할 때의 기본적인 순서입니다.

1.  **저장소 생성 (New Repository)**
    > GitHub에서 원격 저장소를 새로 만듭니다. 이때 `README.md` 파일을 추가하는 것이 좋습니다.

2.  **클론 (Clone)**
    > 원격 저장소를 내 컴퓨터로 복제합니다.
    ```bash
    # 'YourUsername'과 'YourRepository'를 실제 정보로 바꾸세요.
    git clone https://github.com/YourUsername/YourRepository.git
    ```

3.  **수정 및 커밋 (Edit & Commit)**
    > 파일을 수정하고, 변경사항을 스테이징(add)한 뒤, 메시지와 함께 로컬 저장소에 기록(commit)합니다.
    ```bash
    # 수정된 파일을 스테이징합니다.
    git add README.md

    # 변경사항을 메시지와 함께 커밋합니다.
    git commit -m "여기에 커밋 메시지를 작성합니다"
    ```

4.  **푸시 (Push)**
    > 로컬 저장소의 변경사항을 원격 저장소로 업로드합니다.
    ```bash
    git push
    ```

### 🤝 협업 흐름 (Collaboration Workflow)

다른 사람의 프로젝트에 기여(Contribute)할 때의 표준적인 순서입니다.

1.  **포크 (Fork)**
    > 다른 사람의 원격 저장소를 내 GitHub 계정으로 복사합니다.

2.  **클론 (Clone)**
    > **포크해온 내 계정의 저장소**를 내 컴퓨터로 복제합니다.
    ```bash
    # 'MyUsername'을 자신의 GitHub 계정으로, 'ForkedRepository'를 포크한 저장소 이름으로 바꾸세요.
    git clone https://github.com/MyUsername/ForkedRepository.git
    ```

3.  **브랜치 생성 및 수정 (Branch & Edit)**
    > 원본에 영향을 주지 않도록 새로운 브랜치를 만들고, 그 브랜치 안에서 코드를 수정하고 커밋합니다.
    ```bash
    # 'new-feature'라는 이름의 새 브랜치를 만들고 그 브랜치로 이동합니다.
    git checkout -b new-feature

    # 코드를 수정한 뒤, 평소처럼 add/commit 합니다.
    git add .
    git commit -m "새로운 기능 추가"
    ```

4.  **푸시 (Push)**
    > **내 로컬 브랜치**의 변경사항을 **내 원격 저장소(포크한 저장소)**로 업로드합니다.
    ```bash
    # 'new-feature' 브랜치를 원격 저장소(origin)로 푸시합니다.
    git push origin new-feature
    ```

5.  **풀 리퀘스트 (Pull Request - PR)**
    > 내 GitHub 저장소에서 원본 저장소로 "이 변경사항을 합쳐주세요"라고 요청을 보냅니다.

6.  **머지 (Merge)**
    > 원본 저장소의 주인이 코드를 검토한 후, 문제가 없으면 `main` 브랜치로 변경사항을 합칩니다.