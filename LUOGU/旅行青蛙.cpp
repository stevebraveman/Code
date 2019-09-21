#include <bits/stdc++.h>
#include <string>
#define version "1.0.1"
#define ut 10000000ll
#define inf 2147483647
using namespace std;

int tempi;
bool isathome;
unsigned int foodchosen;
unsigned int luckchosen;
unsigned int usechosen;
bool settled;
map <int,int> w;

class frog{
    public:
        unsigned long long outtime,lasttime;
        string name;
};

class game{
    public:
        frog yourfrog;
        unsigned int clover;
        unsigned int lottery;
        unsigned int things[40];
        unsigned int lasttime;
};

unsigned int chosen[40]={0};
string tn[40]={"葡萄干司康","鹅肠菜三明治","南瓜百吉饼","乳蛋饼","艾蒿小麦饼",
                "胡葱炸面包","胡萝卜饼干","南瓜饼干","毛豆饼干","牛奶饼干","牛蒡饼干",
                "草莓金平糖","柠檬金平糖","葡萄金平糖","蜜瓜金平糖","四叶草",
                "黄色护身符","白色护身符","红色护身符","蓝色护身符","桃色护身符",
                "东国车票","西国车票","南国车票","北国车票","幸运之铃",
                "头巾（地）","头巾（木）","头巾（装）","天然帐篷","时髦帐篷","高档帐篷",
                "透明的碗","木碗","漆器","蜡烛","手提灯笼","欧式提灯"};
unsigned int price[40]={10,20,50,80,100,
                        100,inf,inf,inf,inf,inf,
                        inf,inf,inf,inf,inf,
                        inf,inf,inf,inf,inf,
                        inf,inf,inf,inf,3000,
                        150,250,400,300,450,750,
                        450,700,1200,600,900,1500};

game yourgame;

void save(){
    FILE * out=fopen("tabikaeru.txt","w");
    fprintf(out,"%s\n",yourgame.yourfrog.name.c_str());
    fprintf(out,"%llu\n%llu\n",yourgame.yourfrog.outtime,yourgame.yourfrog.lasttime);
    fprintf(out,"%u\n%u\n",yourgame.clover,yourgame.lottery);
    fprintf(out,"%d\n%u\n%u\n%u\n",settled,foodchosen,luckchosen,usechosen);
    for (int i=0;i<39;i++) fprintf(out,"%u\n",yourgame.things[i]);
    fprintf(out,"%u\n",yourgame.lasttime);
    fprintf(out,"%d\n",isathome);
    fclose(out);
}

void read(){
    ifstream in("tabikaeru.txt");
    in>>yourgame.yourfrog.name>>yourgame.yourfrog.outtime>>yourgame.yourfrog.lasttime>>yourgame.clover>>yourgame.lottery;
    in>>settled>>foodchosen>>luckchosen>>usechosen;
    for (int i=0;i<39;i++) in>>yourgame.things[i];
    in>>yourgame.lasttime;
    in>>isathome;
    in.close();
}

void delay(long long t){
    for (int i=0;i<t;i++);
}

void welcome(){
    cout<<"旅行青蛙  version"<<version<<"  by Flokirie"<<endl;
    delay(40*ut);
    for (int i=0;i<=100;i++){
        printf("加载中……   %d%%\r",i);
        delay(2*ut);
    }
    delay(30*ut);
    cout<<endl<<endl<<"加载完成！"<<endl;
    delay(60*ut);
}

string input(string s){
    cout<<">>>";
    cin>>s;
    return s;
}

int input(int i){
    cout<<">>>";
    cin>>i;
    return i;
}

int result(int num){
    if (num>32000) {
        return 1;
    }
    else if (num>30000){
        return 2;
    }
    else if (num>24000){
        return 3;
    }
    else if (num>14000){
        return 4;
    }
    else return 5;
}

void init(){
    cout<<endl<<"这里是你的花园。";
    delay(75*ut);
    cout<<endl<<"去家里看看吧。";
    delay(75*ut);
    cout<<endl<<"这是你家的青蛙。";
    delay(60*ut);
    cout<<endl<<"它可是一只爱旅行的青蛙。";
    delay(80*ut);
    cout<<endl<<"给它取个名字吧（最大5文字）：\n※以后还可以更改"<<endl;
    yourgame.yourfrog.name=input(yourgame.yourfrog.name);
    delay(40*ut);
    cout<<yourgame.yourfrog.name<<"正在收拾行囊，看起来很开心。"<<endl;
    delay(55*ut);
    cout<<"让我们再次来到花园。"<<endl;
    delay(50*ut);
    cout<<"看那些三叶草啊！"<<endl;
    delay(50*ut);
    cout<<"快去收割它们吧。"<<endl;
    delay(35*ut);
    cout<<"\n选项\n1.收割三叶草"<<endl;
    delay(28*ut);
    while (input(tempi)!=1){
        cout<<"输入有误！请重新输入："<<endl;
        delay(25*ut); 
    }
    delay(35*ut);
    cout<<"三叶草 19 已获得"<<endl;
    delay(35*ut);
    yourgame.clover+=19;
    cout<<"还获得了 四叶草 1"<<endl;
    delay(50*ut);
    cout<<"现在，去商店为"<<yourgame.yourfrog.name<<"做些准备吧。"<<endl;
    delay(32*ut);
    cout<<"\n选项\n1.商店"<<endl;
    while (input(tempi)!=1){
        cout<<"输入有误！请重新输入："<<endl;
        delay(25*ut); 
    }
    delay(50*ut);
    cout<<"现在也没什么可买的，我们买个葡萄干司康吧。"<<endl;
    delay(55*ut);
    cout<<"\n购买：\n1.葡萄干司康（10 三叶草）\n";
    delay(30*ut);
    while (input(tempi)!=1){
        cout<<"输入有误！请重新输入："<<endl;
        delay(25*ut);
    }
    yourgame.clover-=10;
    delay(27*ut);
    cout<<"好，去帮"<<yourgame.yourfrog.name<<"准备行囊吧：" ;
    delay(50*ut);
    cout<<"\n\n选项：\n1.回家\n";
    delay(30*ut);
    while (input(tempi)!=1){
        cout<<"输入有误！请重新输入："<<endl;
        delay(25*ut);
    }
    delay(30*ut);
    cout<<"\n选项：\n1.收拾行囊\n";
    delay(30*ut);
    while (input(tempi)!=1){
        cout<<"输入有误！请重新输入："<<endl;
        delay(25*ut);
    }
    delay(30*ut);
    cout<<"\n行囊：\n1.便当\n";
    delay(30*ut);
    while (input(tempi)!=1){
        cout<<"输入有误！请重新输入："<<endl;
        delay(25*ut);
    }
    delay(28*ut);
    cout<<"\n便当：\n1.葡萄干司康 （所持 1）\n";
    delay(30*ut);
    while (input(tempi)!=1){
        cout<<"输入有误！请重新输入："<<endl;
        delay(25*ut);
    }
    delay(28*ut); 
    cout<<"\n行囊：\n1.幸运物\n";
    delay(30*ut);
    while (input(tempi)!=1){
        cout<<"输入有误！请重新输入："<<endl;
        delay(25*ut);
    }
    delay(27*ut);
    cout<<"\n幸运物：\n1.四叶草 （所持 1）\n";
    delay(30*ut);
    while (input(tempi)!=1){
        cout<<"输入有误！请重新输入："<<endl;
        delay(25*ut);
    }
    delay(30*ut);
    cout<<"\n行囊：\n1.确定\n";
    delay(30*ut);
    while (input(tempi)!=1){
        cout<<"输入有误！请重新输入："<<endl;
        delay(25*ut);
    }
    delay(35*ut);
    cout<<"你已经为"<<yourgame.yourfrog.name<<"完成了旅行准备。"<<endl; 
    cout<<"※由于这是教程，所以"<<yourgame.yourfrog.name<<"会在重启本程序后踏上旅程。";
    yourgame.yourfrog.outtime=time(0)+1;
    yourgame.yourfrog.lasttime=1800;
    yourgame.lasttime=time(0)+1;
    save();
}

void play();
void shop();
void garden();
void home();
void bedroom();
void prize();
void buy();

/*
0 葡萄干司康 1 鹅肠菜三明治 2 南瓜百吉饼 3 乳蛋饼 4 艾蒿小麦饼 5 胡葱炸面包 6~10 饼干 11~14 金平糖
15 四叶草 16~20 护身符 21~24 车票 25 幸运铃 
26~29 头巾 30~32 帐篷 33~35 漆器 36~38 提灯  
*/

int main(){
    srand(time(0));
    welcome();
    FILE * in=fopen("tabikaeru.txt","r");
    if (in==NULL){
        init();
    }
    else{
        read();
        play();
        save();
    }
    return 0;
}

void play(){
    if (isathome==0 &&(unsigned long long)(time(0))>yourgame.yourfrog.outtime+yourgame.yourfrog.lasttime){
        cout<<yourgame.yourfrog.name<<"已经回来了"<<endl;
        isathome=1;
        delay(80*ut);
    }
    else if (isathome){
        cout<<yourgame.yourfrog.name<<"在家里。"<<endl;
    }
    else if ((unsigned long long)(time(0))>yourgame.yourfrog.outtime) {
        cout<<yourgame.yourfrog.name<<"已经踏上旅程"<<endl;
        isathome=0;
        delay(80*ut);
    }
    else isathome=0;
    garden();
    return;
}

void shop(){
    delay(40*ut);
    cout<<"\n这里是商店。"<<endl<<endl;
    delay(35*ut);
    cout<<"选项：\n1.抽奖\n2.买东西\n3.回家\n4.去花园\n";
    delay(30*ut);
    tempi=input(tempi);
    while(tempi>4 || tempi<1){
        cout<<"输入有误！请重新输入："<<endl;
        delay(25*ut);
        tempi=input(tempi);
    }
    delay(30*ut);
    switch(tempi){
        case 1:
            prize();
            break;
        case 2:
            buy();
            break;
        case 3:
            home();
            break;
        case 4:
            garden();
            break;
    }
}

void garden(){
    delay(40*ut);
    cout<<"\n这是你的花园。"<<endl<<endl;
    delay(35*ut);
    a:  cout<<"选项：\n1.收割三叶草\n2.回家\n3.去商店\n4.去里屋\n5.充值\n6.保存并退出\n";
    delay(30*ut);
    tempi=input(tempi);
    while(tempi>6 || tempi<1){
        cout<<"输入有误！请重新输入："<<endl;
        delay(25*ut);
        tempi=input(tempi);
    }
    delay(30*ut);
    switch(tempi){
        case 2:
            home();
            break;
        case 3:
            shop();
            break;
        case 4:
            bedroom();
            break;
        case 5:
            cout<<"就这C++版旅行青蛙还想充值？"<<endl;
            delay(35*ut);
            goto a;
        case 6:
            save();
            break;
        case 1:
            int numb=max(min((int)((time(0)-yourgame.lasttime)/500),20),0);
            int four=0;
            for (int i=0;i<numb;i++){
                if (rand()%300==0) four++;
            }
            if (four) four=1;
            cout<<"三叶草 "<<numb-four<<" 已获得"<<endl;
            delay(35*ut);
            yourgame.clover+=numb-four;
            if (four) 
            {
                cout<<"还获得了 四叶草 1"<<endl;
                yourgame.things[15]++;
            }
            yourgame.lasttime=time(0)+1;
            delay(28);
            goto a;
            break;
    }
}

void home(){
    delay(30*ut);
    cout<<"这里是你的家。"<<endl;
    delay(32*ut);
    if (!isathome){
        c:  cout<<"选项：\n1.去花园\n2.去商店\n3.去里屋\n4.保存并退出\n";
        delay(30*ut);
        tempi=input(tempi);
        while(tempi>4 || tempi<1){
            cout<<"输入有误！请重新输入："<<endl;
            delay(25*ut);
            tempi=input(tempi);
        }
        delay(30*ut);
        switch(tempi){
            case 1:
                garden();
                break;
            case 2:
                shop();
                break;
            case 3:
                bedroom();
                break;
            case 4:
                save();
                break;
        }
    }
    else{
        cc: cout<<"选项：\n1.去花园\n2.去商店\n3.去里屋\n4.给蛙改名\n5.收拾行囊\n6.保存并退出\n";
        delay(30*ut);
        tempi=input(tempi);
        while(tempi>6 || tempi<1){
            cout<<"输入有误！请重新输入："<<endl;
            delay(25*ut);
            tempi=input(tempi);
        }
        delay(30*ut);
        switch(tempi){
            case 1:
                garden();
                break;
            case 2:
                shop();
                break;
            case 3:
                bedroom();
                break;
            case 4:
                cout<<"请输入蛙的新名字（最大5文字）："<<endl;
                delay(35*ut);
                yourgame.yourfrog.name=input(yourgame.yourfrog.name);
                goto cc;
                break;
            case 5:
                if (settled){
                    cout<<"行囊已经准备好了！"<<endl;
                    delay(40*ut);
                    goto c;
                }
                d:  cout<<"\n行囊：\n1.便当\n2.幸运物\n3.用具\n4.确认\n5.返回选项\n";
                delay(40*ut);
                tempi=input(tempi);
                while(tempi>5 || tempi<1){
                    cout<<"输入有误！请重新输入："<<endl;
                    delay(25*ut);
                    tempi=input(tempi);
                }
                delay(30*ut);
                switch (tempi){
                    case 1:{
                        cout<<endl<<"便当："<<endl;
                        int order=1;
                        for (int i=0;i<15;i++){
                            if (yourgame.things[i]){
                                cout<<order++<<"."<<tn[i]<<" （所持 "<<yourgame.things[i]<<"）"<<endl;
                            } 
                        }
                        cout<<order<<".不保存并返回上一级"<<endl;
                        delay(35*ut);
                        tempi=input(tempi);
                        while(tempi>order || tempi<1){
                            cout<<"输入有误！请重新输入："<<endl;
                            delay(25*ut);
                            tempi=input(tempi);
                        }
                        if (tempi==order) goto d;
                        int i=0,j=0;
                        do{
                            if (yourgame.things[i]) j++;
                            i++;
                        }while(j<order);
                        if (foodchosen==1) {
                            cout<<"便当已装满！"<<endl;
                            goto d;
                        }
                        foodchosen=!foodchosen;
                        chosen[i]=!chosen[i];
                        cout<<"已成功选择。"<<endl;
                        delay(45*ut);
                        goto d;
                        break;
                    }
                    case 2:{
                        cout<<endl<<"幸运物："<<endl;
                        int order=1;
                        for (int i=15;i<26;i++){
                            if (yourgame.things[i]){
                                cout<<order++<<"."<<tn[i]<<" （所持 "<<yourgame.things[i]<<"）"<<endl;
                            } 
                        }
                        cout<<order<<".不保存并返回上一级"<<endl;
                        delay(35*ut);
                        tempi=input(tempi);
                        while(tempi>order || tempi<1){
                            cout<<"输入有误！请重新输入："<<endl;
                            delay(25*ut);
                            tempi=input(tempi);
                        }
                        if (tempi==order) goto d;
                        int i=16,j=0;
                        do{
                            if (yourgame.things[i]) j++;
                            i++;
                        }while(j<order);
                        if (luckchosen==1) {
                            cout<<"幸运物已装满！"<<endl;
                            goto d;
                        }
                        luckchosen=!luckchosen;
                        chosen[i]=!chosen[i];
                        cout<<"已成功选择。"<<endl;
                        delay(45*ut);
                        goto d;
                        break;
                    }
                    case 3:{
                        cout<<endl<<"用品："<<endl;
                        int order=1;
                        for (int i=26;i<39;i++){
                            if (yourgame.things[i]){
                                cout<<order++<<"."<<tn[i]<<" （所持 "<<yourgame.things[i]<<"）"<<endl;
                            } 
                        }
                        cout<<order<<".不保存并返回上一级"<<endl;
                        delay(35*ut);
                        tempi=input(tempi);
                        while(tempi>order || tempi<1){
                            cout<<"输入有误！请重新输入："<<endl;
                            delay(25*ut);
                            tempi=input(tempi);
                        }
                        if (tempi==order) goto d;
                        int i=26,j=0;
                        do{
                            if (yourgame.things[i]) j++;
                            i++;
                        }while(j<order);
                        if (usechosen==2) {
                            cout<<"用品已装满！"<<endl;
                            goto d;
                        }
                        if (chosen[i]) usechosen--;
                        else usechosen++;
                        chosen[i]=!chosen[i];
                        cout<<"已成功选择。"<<endl;
                        delay(45*ut);
                        goto d;
                        break;
                    }
                    case 4:{
                        settled=1;
                        for (int i=0;i<25;i++){
                            if (chosen[i]) yourgame.things[i]-=1;
                        }
                        cout<<"成功收拾好行囊。"<<endl;
                        yourgame.yourfrog.outtime=time(0)+1000+rand()%1000;
                        yourgame.yourfrog.lasttime=10000+rand()%10000+rand()%10000;
                        delay(50*ut);
                    }
                    goto cc;
                }
            case 6:
                save();
                break;
        }
    }
}

void bedroom(){
    delay(20*ut);
    cout<<"这里并没有什么功能。"<<endl;
    delay(25*ut);
    cout<<"选项：\n1.回家"<<endl;
    tempi=input(tempi);
    while(tempi!=1){
        cout<<"输入有误！请重新输入："<<endl;
        delay(25*ut);
        tempi=input(tempi);
    }
    home(); 
}

void prize(){
    delay(36*ut);
    cout<<"这里是摇奖店。"<<endl;
    delay(30*ut);
    b:  cout<<"5张奖券转一次，你有"<<yourgame.lottery<<"张奖券。"<<endl;
    delay(35*ut);
    cout<<"选项：\n1.抽奖\n2.奖品一览\n3.去商店\n4.回家\n";
    delay(30*ut);
    tempi=input(tempi);
    while(tempi>4 || tempi<1){
        cout<<"输入有误！请重新输入："<<endl;
        delay(25*ut);
        tempi=input(tempi);
    }
    delay(90*ut);
    switch(tempi){
        case 1:
            if (yourgame.lottery<5){
                cout<<"对不起，奖券不足，您现在不能抽奖！"<<endl;
                delay(36*ut);
                goto b; 
            }
            yourgame.lottery-=5;
            switch (result(rand())){
                case 1:
                    cout<<endl<<"黄玉 出来了"<<endl;
                    delay(45*ut);
                    cout<<endl<<"请选择奖品："<<endl;
                    delay(30*ut);
                    cout<<endl<<"1.东国车票\n2.西国车票\n3.南国车票\n4.北国车票\n";
                    delay(60*ut);
                    tempi=input(tempi);
                    while(tempi>4 || tempi<1){
                        cout<<"输入有误！请重新输入："<<endl;
                        delay(25*ut);
                        tempi=input(tempi);
                    }
                    delay(30*ut);
                    switch (tempi){
                        case 1:
                            cout<<"获得了 东国车票"<<endl;
                            break;
                        case 2:
                            cout<<"获得了 西国车票"<<endl;
                            break;
                        case 3:
                            cout<<"获得了 南国车票"<<endl;
                            break;
                        case 4:
                            cout<<"获得了 北国车票"<<endl;
                            break;
                    }
                    yourgame.things[21+tempi]++;
                    delay(35*ut);
                    break;
                case 2:
                    cout<<endl<<"红玉 出来了"<<endl;
                    delay(45*ut);
                    cout<<endl<<"请选择奖品："<<endl;
                    delay(30*ut);
                    cout<<endl<<"1.草莓金平糖\n2.柠檬金平糖\n3.葡萄金平糖\n4.蜜瓜金平糖\n";
                    delay(60*ut);
                    tempi=input(tempi);
                    while(tempi>4 || tempi<1){
                        cout<<"输入有误！请重新输入："<<endl;
                        delay(25*ut);
                        tempi=input(tempi);
                    }
                    delay(30*ut);
                    switch (tempi){
                        case 1:
                            cout<<"获得了 草莓金平糖"<<endl;
                            break;
                        case 2:
                            cout<<"获得了 柠檬金平糖"<<endl;
                            break;
                        case 3:
                            cout<<"获得了 葡萄金平糖"<<endl;
                            break;
                        case 4:
                            cout<<"获得了 蜜瓜金平糖"<<endl;
                            break;
                    }
                    yourgame.things[10+tempi]++;
                    delay(35*ut);
                    break;
                case 3:
                    cout<<endl<<"绿玉 出来了"<<endl;
                    delay(45*ut);
                    cout<<endl<<"请选择奖品："<<endl;
                    delay(30*ut);
                    cout<<endl<<"1.胡萝卜饼干\n2.南瓜饼干\n3.毛豆饼干\n4.牛奶饼干\n5.牛蒡饼干";
                    delay(60*ut);
                    tempi=input(tempi);
                    while(tempi>5 || tempi<1){
                        cout<<"输入有误！请重新输入："<<endl;
                        delay(25*ut);
                        tempi=input(tempi);
                    }
                    delay(30*ut);
                    switch (tempi){
                        case 1:
                            cout<<"获得了 胡萝卜饼干"<<endl;
                            break;
                        case 2:
                            cout<<"获得了 南瓜饼干"<<endl;
                            break;
                        case 3:
                            cout<<"获得了 毛豆饼干"<<endl;
                            break;
                        case 4:
                            cout<<"获得了 牛奶饼干"<<endl;
                            break;
                        case 5:
                            cout<<"获得了 牛蒡饼干"<<endl;
                            break;
                    }
                    yourgame.things[5+tempi]++;
                    delay(35*ut);
                    break;
                 case 4:
                    cout<<endl<<"青玉 出来了"<<endl;
                    delay(45*ut);
                    cout<<endl<<"请选择奖品："<<endl;
                    delay(30*ut);
                    cout<<endl<<"1.黄色护身符\n2.白色护身符\n3.红色护身符\n4.蓝色护身符\n5.桃色护身符\n";
                    delay(60*ut);
                    tempi=input(tempi);
                    while(tempi>5 || tempi<1){
                        cout<<"输入有误！请重新输入："<<endl;
                        delay(25*ut);
                        tempi=input(tempi);
                    }
                    delay(30*ut);
                    switch (tempi){
                        case 1:
                            cout<<"获得了 黄色护身符"<<endl;
                            break;
                        case 2:
                            cout<<"获得了 白色护身符"<<endl;
                            break;
                        case 3:
                            cout<<"获得了 红色护身符"<<endl;
                            break;
                        case 4:
                            cout<<"获得了 蓝色护身符"<<endl;
                            break;
                        case 5:
                            cout<<"获得了 桃色护身符"<<endl;
                            break;
                    }
                    yourgame.things[16+tempi]++;
                    delay(35*ut);
                    break;
                case 5:
                    cout<<endl<<"白玉 出来了"<<endl;
                    delay(45*ut);
                    cout<<"获得了 抽奖券"<<endl;
                    yourgame.lottery++;
                    delay(35*ut);
                    break;  
            }
            goto b;
            break;
        case 2:
            cout<<"黄玉   车票\n红玉   金平糖\n绿玉   饼干\n青玉   护身符\n白玉   抽奖券\n";
            delay(45*ut);
            goto b;
            break;
        case 3:
            shop();
            break;
        case 4:
            home();
            break;
    }
}

void buy(){
    ee:delay(35*ut);
    cout<<endl<<"商品一览："<<endl;
    delay(35*ut);
    for (int i=0,j=0;i<38;i++){
        if (price[i]!=inf){
            w[++j]=i;
            cout<<j<<". "<<tn[i]<<"  （三叶草 "<<price[i]<<"）";
            if (i>=25 && i<=37 && yourgame.things[i]) cout<<"  【已售罄】";
            cout<<endl;
            delay(4*ut);
        }
    }
    cout<<endl<<"你所持有的三叶草数：  "<<yourgame.clover<<endl;
    delay(36*ut);
    cout<<endl;
    delay(40*ut);
    cout<<"选项："<<endl<<"（1~19）.输入商品编号以购买"<<endl;
    cout<<"20.回家"<<endl<<"21.去花园"<<endl<<"22.回到“商店”界面"<<endl;
    delay(28*ut);
    tempi=input(tempi);
    while(tempi>22 || tempi<1){
        cout<<"输入有误！请重新输入："<<endl;
        delay(25*ut);
        tempi=input(tempi);
    }
    delay(27*ut);
    if (tempi<=19){
        if (yourgame.clover<price[w[tempi]]){
            cout<<"您持有的三叶草不足！"<<endl;
        }
        else if (w[tempi]>=25 && w[tempi]<=37 && yourgame.things[w[tempi]])
        {
            cout<<tn[w[tempi]]<<"真的已经售罄了！"<<endl<<endl;
        }
        else{
            yourgame.clover-=price[w[tempi]];
            yourgame.things[w[tempi]]++;
            cout<<"已成功购买"<<tn[w[tempi]]<<"，剩余三叶草数：  "<<yourgame.clover<<endl<<endl;
            if (rand()<500){
                cout<<endl<<"还获得了   抽奖券  1"<<endl;
                delay(30);
                yourgame.lottery++;
            }
        }
        goto ee;
    }
    else if (tempi==20){
        home();
    }
    else if (tempi==21){
        garden();
    }
    else{
        shop();
    } 
}
