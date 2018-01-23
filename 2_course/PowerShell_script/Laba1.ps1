param ($path = "C:\Users\acer\Desktop\OS\LabWork_2\pictures", $zero = 7)
Set-Location -Path $path
dir | Where-Object { $_.Extension -eq ".jpg" }  | ForEach-Object {$i=1} {Rename-Item $_ -NewName ("{0:D$zero}.jpg" -f $i++)}
#Get-ChildItem -Path "$path" -Filter "*.jpg" | ForEach-Object {$i=1} {Rename-Item $_ -NewName ("{0:D$zero}.jpg" -f $i++)}