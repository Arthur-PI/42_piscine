cat /etc/passwd | grep -v '\#'| awk 'NR%2==0 {print NR, $0}' | awk -F: '{print $1}' | rev | sort -r | awk '{print $1}' | sed -n "$FT_LINE1,$FT_LINE2 p" | awk 1 ORS=', ' | sed 's/, $/\./' | tr -d '\n'
