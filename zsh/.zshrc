# If you come from bash you might have to change your $PATH.# export PATH=$HOME/bin:/usr/local/bin:$PATH

# Path to your oh-my-zsh installation.
export ZSH=/home/emil/.oh-my-zsh

source "$HOME/.zplug/init.zsh"
source "$HOME/zplug.zsh"

if ! zplug check; then
    zplug install
fi

zplug load

ZSH_THEME="robbyrussell"

plugins=(git vi-mode)

source $ZSH/oh-my-zsh.sh

[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh

source ~/.zsh/zsh-autosuggestions/zsh-autosuggestions.zsh

export GOPATH="/usr/local/lib/go"
export PATH="/usr/lib/go-1.8/bin/:$PATH"
export PATH="/home/emil/.cargo/bin:$PATH"
export MONOREPO="/home/emil/git/edgeware/monorepo"
export SPOTON="/home/emil/git/spoton"

# VIM mode settings
vim_ins_mode="%{$fg[cyan]%}>%{$reset_color%}"
vim_cmd_mode="%{$fg[green]%}|%{$reset_color%}"
vim_mode=$vim_ins_mode

function zle-keymap-select {
    vim_mode="${${KEYMAP/vicmd/${vim_cmd_mode}}/(main|viins)/${vim_ins_mode}}"
    zle reset-prompt
}
zle -N zle-keymap-select

function zle-line-finish {
    vim_mode=$vim_ins_mode
}
zle -N zle-line-finish

# Fix a bug when you C-c in CMD mode and you'd be prompted with CMD mode indicator, while in fact you would be in INS mode
# Fixed by catching SIGINT (C-c), set vim_mode to INS and then repropagate the SIGINT, so if anything else depends on it, we will not break it
# Thanks Ron! (see comments)
function TRAPINT() {
    vim_mode=$vim_ins_mode
    return $(( 128 + $1 ))
}

PROMPT='${ret_status} %{$fg[cyan]%}%c%{$reset_color%} $(git_prompt_info)${vim_mode} '

export KEYTIMEOUT=1

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion

if [ -z "$SSH_AUTH_SOCK" ] ; then
    eval `ssh-agent -s`
    ssh-add
fi

# Aliases
alias spoton="cd ~/git/spoton"
alias edgeware="cd ~/git/edgeware"
alias dotfiles="cd ~/git/dotfiles"
alias cygni="cd ~/git/cygni"
alias TT="cd ~/git/tt"

export PATH="$HOME/.yarn/bin:$HOME/.config/yarn/global/node_modules/.bin:$PATH"
export PATH=${PATH}:$HOME/android-sdk-linux/platform-tools:$HOME/android-sdk-linux/tools:$HOME/android-sdk-linux/build-tools/22.0.1/
export ANDROID_HOME=$HOME/android-sdk-linux
export ANDROID_SDK_ROOT=$HOME/android-sdk-linux

eval $(thefuck --alias)
