syntax enable
imap {<CR> {<CR>}<Esc>O
set t_Co=256
set background=dark
colorscheme desert
set softtabstop=4
set shiftwidth=4
set number
set expandtab
set mouse=a
set ruler
filetype indent on
filetype plugin indent on

autocmd BufNewFile *.cpp :0r ~/.template.cpp
