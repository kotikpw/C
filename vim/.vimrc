" Author KOTIK
" git@github.com:kotikpw/C.git

behave mswin

set encoding=utf-8
set sw=8
set number
set autoindent
set bs=2
set smarttab
syntax on

highlight ExtraWhitespace ctermbg=red guibg=red
match ExtraWhitespace /\s\+$/
match ExtraWhitespace /\s\+$\| \+\ze\t/


