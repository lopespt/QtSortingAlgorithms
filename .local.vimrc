" unmap <C-F11>
map <C-F11> :! ~/Qt/5.2.1/clang_64/bin/qmake -project; echo 'QT += core gui widgets' >> qtComVim.pro; make <CR>

inoremap <C-F12> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<cr>      
inoremap <C-F12> <Esc>:!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q .<cr>
