#!/bin/bash

if [ -z "$1" -o ! -e "$1" ]; then
    echo "parameters missed OR folder '$1' not exists"
    exit 1
fi

files=$(find "$1" -name "*.html")
reg='<script\s*type="text/javascript">window.BUILD_ENV\s*=\s*"beta"</script>'
rep='s/<head>/<head>\n\t<script type="text\/javascript">window.BUILD_ENV = "beta"<\/script>/'

for filename in $files
do
    grep -Eq "$reg" "$filename" || (
        if [[ "$OSTYPE" == "darwin"* ]]; then
            sed -i '' "$rep" "$filename"
        else
            sed -i "$rep" "$filename"
        fi
    )
done

