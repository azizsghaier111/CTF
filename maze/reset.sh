#/bin/bash
rm 19/"$(for i in $(seq -s" " 1 1000); do echo "d/"; done | tr -d '\r\n')"/lnk
ln -f -s ~/txt.txt ~/19/"$(for i in $(seq -s" " 1 1000); do echo "d/"; done | tr -d '\r\n')"/lnk
