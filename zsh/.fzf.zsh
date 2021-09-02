# Setup fzf
# ---------
if [[ ! "$PATH" == */Users/emil/.fzf/bin* ]]; then
  export PATH="${PATH:+${PATH}:}/Users/emil/.fzf/bin"
fi

# Auto-completion
# ---------------
[[ $- == *i* ]] && source "/Users/emil/.fzf/shell/completion.zsh" 2> /dev/null

# Key bindings
# ------------
source "/Users/emil/.fzf/shell/key-bindings.zsh"
