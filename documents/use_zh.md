# 如何使用 GitHub

## 準備工作
1. 申請一個 GitHub 帳號，認證好你的 gmail，這樣才可以協作
2. 裝好 Windows 裡的 WSL 作為運行環境
3. 確定你的 VScode 可以連上 WSL

## 開搞
### 確定你的 WSL 裡有 git

用這個指令確認 git 是否存在
```
git --version
```

如果報錯的話，表示你的 WSL 裡沒有 git，用以下指令下載 git
```
sudo apt update
sudo apt install git
```

### 設定你的 git 
設定你的 git，讓他知道你申請 GitHub 的 email 和 name \
別忘了雙引號
```
git config --global user.email "you@example.com"
git config --global user.name "Your Name"
```


### 克隆一份專案到本地
挑個喜歡的地方，用這個指令把專案拉到本地來
```
git clone https://github.com/nakiridaisuki/linear_algebra_final_project.git
```

### 新增你的分支
為了避免大家的修改打架，所以請自己創一個分支出來，並在自己的分支裡把自己的 task 完成\
新建一個分支，並切換到他：
```
git checkout -b [branch name]
```
請各位命名好自己的分支名稱（不用中括號）

## 當你寫完你的 code 後

### 紀錄修改的東西
在 CHANGELOG 裡打上你修改的東西，這樣再出現 BUG 時比較方便定位問題。\
CHANGELOG 的寫法[參考](./changelogtemplate.md)

### 提交修改
當你寫好你的東西後，使用這些指令把你的修改提交到你的分支上，並推送到 GitHub 上 \
記得寫好 commit 時的訊息，以及打好你的分支名稱
```
git add -A
git commit -m "modify message"
git push origine [your branch name]
```