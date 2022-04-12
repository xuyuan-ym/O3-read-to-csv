for f in *.*,*
do
export latc=`echo $f | cut -c 1-6`
export lonc=`echo $f | cut -c 8-13`
export height=1
export citys=$f
m4 -Dlat=${latc} -Dlon=${lonc} -Dcity=${height} -Dcity=${citys} o3ncl > temp
done

