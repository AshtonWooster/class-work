n=$100
m=$100
for((i=0;i<n;i++)); do
    for((j=0;j<m;j++)); do
        p=$( expr $i + $j )
        echo "$p"
    done
done
