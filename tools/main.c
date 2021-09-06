void main(){
    int x = 12;
    int y = 3;
    int a = 0;

    if (x > y){
        if(x < 10){
            a = x - y;
        }else {
            a = x + y;
        }
    } else {
        a = y - x;
    }
}