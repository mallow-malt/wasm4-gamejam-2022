Get-ChildItem *.aseprite | Foreach {aseprite -b $_.name --save-as $_.name.Replace(".aseprite", ".png") | Out-Null}
w4 png2src --c -o sprites.h -t png2srctemplate ((Get-ChildItem *.png | select -ExpandProperty Name))
