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
string tn[40]={"���Ѹ�˾��","�쳦��������","�Ϲϰټ���","�鵰��","����С���",
                "����ը���","���ܲ�����","�Ϲϱ���","ë������","ţ�̱���","ţ�����",
                "��ݮ��ƽ��","���ʽ�ƽ��","���ѽ�ƽ��","�۹Ͻ�ƽ��","��Ҷ��",
                "��ɫ�����","��ɫ�����","��ɫ�����","��ɫ�����","��ɫ�����",
                "������Ʊ","������Ʊ","�Ϲ���Ʊ","������Ʊ","����֮��",
                "ͷ���أ�","ͷ��ľ��","ͷ��װ��","��Ȼ����","ʱ������","�ߵ�����",
                "͸������","ľ��","����","����","�������","ŷʽ���"};
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
    cout<<"��������  version"<<version<<"  by Flokirie"<<endl;
    delay(40*ut);
    for (int i=0;i<=100;i++){
        printf("�����С���   %d%%\r",i);
        delay(2*ut);
    }
    delay(30*ut);
    cout<<endl<<endl<<"������ɣ�"<<endl;
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
    cout<<endl<<"��������Ļ�԰��";
    delay(75*ut);
    cout<<endl<<"ȥ���￴���ɡ�";
    delay(75*ut);
    cout<<endl<<"������ҵ����ܡ�";
    delay(60*ut);
    cout<<endl<<"������һֻ�����е����ܡ�";
    delay(80*ut);
    cout<<endl<<"����ȡ�����ְɣ����5���֣���\n���Ժ󻹿��Ը���"<<endl;
    yourgame.yourfrog.name=input(yourgame.yourfrog.name);
    delay(40*ut);
    cout<<yourgame.yourfrog.name<<"������ʰ���ң��������ܿ��ġ�"<<endl;
    delay(55*ut);
    cout<<"�������ٴ�������԰��"<<endl;
    delay(50*ut);
    cout<<"����Щ��Ҷ�ݰ���"<<endl;
    delay(50*ut);
    cout<<"��ȥ�ո����ǰɡ�"<<endl;
    delay(35*ut);
    cout<<"\nѡ��\n1.�ո���Ҷ��"<<endl;
    delay(28*ut);
    while (input(tempi)!=1){
        cout<<"�����������������룺"<<endl;
        delay(25*ut); 
    }
    delay(35*ut);
    cout<<"��Ҷ�� 19 �ѻ��"<<endl;
    delay(35*ut);
    yourgame.clover+=19;
    cout<<"������� ��Ҷ�� 1"<<endl;
    delay(50*ut);
    cout<<"���ڣ�ȥ�̵�Ϊ"<<yourgame.yourfrog.name<<"��Щ׼���ɡ�"<<endl;
    delay(32*ut);
    cout<<"\nѡ��\n1.�̵�"<<endl;
    while (input(tempi)!=1){
        cout<<"�����������������룺"<<endl;
        delay(25*ut); 
    }
    delay(50*ut);
    cout<<"����Ҳûʲô����ģ�����������Ѹ�˾���ɡ�"<<endl;
    delay(55*ut);
    cout<<"\n����\n1.���Ѹ�˾����10 ��Ҷ�ݣ�\n";
    delay(30*ut);
    while (input(tempi)!=1){
        cout<<"�����������������룺"<<endl;
        delay(25*ut);
    }
    yourgame.clover-=10;
    delay(27*ut);
    cout<<"�ã�ȥ��"<<yourgame.yourfrog.name<<"׼�����Ұɣ�" ;
    delay(50*ut);
    cout<<"\n\nѡ�\n1.�ؼ�\n";
    delay(30*ut);
    while (input(tempi)!=1){
        cout<<"�����������������룺"<<endl;
        delay(25*ut);
    }
    delay(30*ut);
    cout<<"\nѡ�\n1.��ʰ����\n";
    delay(30*ut);
    while (input(tempi)!=1){
        cout<<"�����������������룺"<<endl;
        delay(25*ut);
    }
    delay(30*ut);
    cout<<"\n���ң�\n1.�㵱\n";
    delay(30*ut);
    while (input(tempi)!=1){
        cout<<"�����������������룺"<<endl;
        delay(25*ut);
    }
    delay(28*ut);
    cout<<"\n�㵱��\n1.���Ѹ�˾�� ������ 1��\n";
    delay(30*ut);
    while (input(tempi)!=1){
        cout<<"�����������������룺"<<endl;
        delay(25*ut);
    }
    delay(28*ut); 
    cout<<"\n���ң�\n1.������\n";
    delay(30*ut);
    while (input(tempi)!=1){
        cout<<"�����������������룺"<<endl;
        delay(25*ut);
    }
    delay(27*ut);
    cout<<"\n�����\n1.��Ҷ�� ������ 1��\n";
    delay(30*ut);
    while (input(tempi)!=1){
        cout<<"�����������������룺"<<endl;
        delay(25*ut);
    }
    delay(30*ut);
    cout<<"\n���ң�\n1.ȷ��\n";
    delay(30*ut);
    while (input(tempi)!=1){
        cout<<"�����������������룺"<<endl;
        delay(25*ut);
    }
    delay(35*ut);
    cout<<"���Ѿ�Ϊ"<<yourgame.yourfrog.name<<"���������׼����"<<endl; 
    cout<<"���������ǽ̳̣�����"<<yourgame.yourfrog.name<<"���������������̤���ó̡�";
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
0 ���Ѹ�˾�� 1 �쳦�������� 2 �Ϲϰټ��� 3 �鵰�� 4 ����С��� 5 ����ը��� 6~10 ���� 11~14 ��ƽ��
15 ��Ҷ�� 16~20 ����� 21~24 ��Ʊ 25 ������ 
26~29 ͷ�� 30~32 ���� 33~35 ���� 36~38 ���  
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
        cout<<yourgame.yourfrog.name<<"�Ѿ�������"<<endl;
        isathome=1;
        delay(80*ut);
    }
    else if (isathome){
        cout<<yourgame.yourfrog.name<<"�ڼ��"<<endl;
    }
    else if ((unsigned long long)(time(0))>yourgame.yourfrog.outtime) {
        cout<<yourgame.yourfrog.name<<"�Ѿ�̤���ó�"<<endl;
        isathome=0;
        delay(80*ut);
    }
    else isathome=0;
    garden();
    return;
}

void shop(){
    delay(40*ut);
    cout<<"\n�������̵ꡣ"<<endl<<endl;
    delay(35*ut);
    cout<<"ѡ�\n1.�齱\n2.����\n3.�ؼ�\n4.ȥ��԰\n";
    delay(30*ut);
    tempi=input(tempi);
    while(tempi>4 || tempi<1){
        cout<<"�����������������룺"<<endl;
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
    cout<<"\n������Ļ�԰��"<<endl<<endl;
    delay(35*ut);
    a:  cout<<"ѡ�\n1.�ո���Ҷ��\n2.�ؼ�\n3.ȥ�̵�\n4.ȥ����\n5.��ֵ\n6.���沢�˳�\n";
    delay(30*ut);
    tempi=input(tempi);
    while(tempi>6 || tempi<1){
        cout<<"�����������������룺"<<endl;
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
            cout<<"����C++���������ܻ����ֵ��"<<endl;
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
            cout<<"��Ҷ�� "<<numb-four<<" �ѻ��"<<endl;
            delay(35*ut);
            yourgame.clover+=numb-four;
            if (four) 
            {
                cout<<"������� ��Ҷ�� 1"<<endl;
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
    cout<<"��������ļҡ�"<<endl;
    delay(32*ut);
    if (!isathome){
        c:  cout<<"ѡ�\n1.ȥ��԰\n2.ȥ�̵�\n3.ȥ����\n4.���沢�˳�\n";
        delay(30*ut);
        tempi=input(tempi);
        while(tempi>4 || tempi<1){
            cout<<"�����������������룺"<<endl;
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
        cc: cout<<"ѡ�\n1.ȥ��԰\n2.ȥ�̵�\n3.ȥ����\n4.���ܸ���\n5.��ʰ����\n6.���沢�˳�\n";
        delay(30*ut);
        tempi=input(tempi);
        while(tempi>6 || tempi<1){
            cout<<"�����������������룺"<<endl;
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
                cout<<"�������ܵ������֣����5���֣���"<<endl;
                delay(35*ut);
                yourgame.yourfrog.name=input(yourgame.yourfrog.name);
                goto cc;
                break;
            case 5:
                if (settled){
                    cout<<"�����Ѿ�׼�����ˣ�"<<endl;
                    delay(40*ut);
                    goto c;
                }
                d:  cout<<"\n���ң�\n1.�㵱\n2.������\n3.�þ�\n4.ȷ��\n5.����ѡ��\n";
                delay(40*ut);
                tempi=input(tempi);
                while(tempi>5 || tempi<1){
                    cout<<"�����������������룺"<<endl;
                    delay(25*ut);
                    tempi=input(tempi);
                }
                delay(30*ut);
                switch (tempi){
                    case 1:{
                        cout<<endl<<"�㵱��"<<endl;
                        int order=1;
                        for (int i=0;i<15;i++){
                            if (yourgame.things[i]){
                                cout<<order++<<"."<<tn[i]<<" ������ "<<yourgame.things[i]<<"��"<<endl;
                            } 
                        }
                        cout<<order<<".�����沢������һ��"<<endl;
                        delay(35*ut);
                        tempi=input(tempi);
                        while(tempi>order || tempi<1){
                            cout<<"�����������������룺"<<endl;
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
                            cout<<"�㵱��װ����"<<endl;
                            goto d;
                        }
                        foodchosen=!foodchosen;
                        chosen[i]=!chosen[i];
                        cout<<"�ѳɹ�ѡ��"<<endl;
                        delay(45*ut);
                        goto d;
                        break;
                    }
                    case 2:{
                        cout<<endl<<"�����"<<endl;
                        int order=1;
                        for (int i=15;i<26;i++){
                            if (yourgame.things[i]){
                                cout<<order++<<"."<<tn[i]<<" ������ "<<yourgame.things[i]<<"��"<<endl;
                            } 
                        }
                        cout<<order<<".�����沢������һ��"<<endl;
                        delay(35*ut);
                        tempi=input(tempi);
                        while(tempi>order || tempi<1){
                            cout<<"�����������������룺"<<endl;
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
                            cout<<"��������װ����"<<endl;
                            goto d;
                        }
                        luckchosen=!luckchosen;
                        chosen[i]=!chosen[i];
                        cout<<"�ѳɹ�ѡ��"<<endl;
                        delay(45*ut);
                        goto d;
                        break;
                    }
                    case 3:{
                        cout<<endl<<"��Ʒ��"<<endl;
                        int order=1;
                        for (int i=26;i<39;i++){
                            if (yourgame.things[i]){
                                cout<<order++<<"."<<tn[i]<<" ������ "<<yourgame.things[i]<<"��"<<endl;
                            } 
                        }
                        cout<<order<<".�����沢������һ��"<<endl;
                        delay(35*ut);
                        tempi=input(tempi);
                        while(tempi>order || tempi<1){
                            cout<<"�����������������룺"<<endl;
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
                            cout<<"��Ʒ��װ����"<<endl;
                            goto d;
                        }
                        if (chosen[i]) usechosen--;
                        else usechosen++;
                        chosen[i]=!chosen[i];
                        cout<<"�ѳɹ�ѡ��"<<endl;
                        delay(45*ut);
                        goto d;
                        break;
                    }
                    case 4:{
                        settled=1;
                        for (int i=0;i<25;i++){
                            if (chosen[i]) yourgame.things[i]-=1;
                        }
                        cout<<"�ɹ���ʰ�����ҡ�"<<endl;
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
    cout<<"���ﲢû��ʲô���ܡ�"<<endl;
    delay(25*ut);
    cout<<"ѡ�\n1.�ؼ�"<<endl;
    tempi=input(tempi);
    while(tempi!=1){
        cout<<"�����������������룺"<<endl;
        delay(25*ut);
        tempi=input(tempi);
    }
    home(); 
}

void prize(){
    delay(36*ut);
    cout<<"������ҡ���ꡣ"<<endl;
    delay(30*ut);
    b:  cout<<"5�Ž�ȯתһ�Σ�����"<<yourgame.lottery<<"�Ž�ȯ��"<<endl;
    delay(35*ut);
    cout<<"ѡ�\n1.�齱\n2.��Ʒһ��\n3.ȥ�̵�\n4.�ؼ�\n";
    delay(30*ut);
    tempi=input(tempi);
    while(tempi>4 || tempi<1){
        cout<<"�����������������룺"<<endl;
        delay(25*ut);
        tempi=input(tempi);
    }
    delay(90*ut);
    switch(tempi){
        case 1:
            if (yourgame.lottery<5){
                cout<<"�Բ��𣬽�ȯ���㣬�����ڲ��ܳ齱��"<<endl;
                delay(36*ut);
                goto b; 
            }
            yourgame.lottery-=5;
            switch (result(rand())){
                case 1:
                    cout<<endl<<"���� ������"<<endl;
                    delay(45*ut);
                    cout<<endl<<"��ѡ��Ʒ��"<<endl;
                    delay(30*ut);
                    cout<<endl<<"1.������Ʊ\n2.������Ʊ\n3.�Ϲ���Ʊ\n4.������Ʊ\n";
                    delay(60*ut);
                    tempi=input(tempi);
                    while(tempi>4 || tempi<1){
                        cout<<"�����������������룺"<<endl;
                        delay(25*ut);
                        tempi=input(tempi);
                    }
                    delay(30*ut);
                    switch (tempi){
                        case 1:
                            cout<<"����� ������Ʊ"<<endl;
                            break;
                        case 2:
                            cout<<"����� ������Ʊ"<<endl;
                            break;
                        case 3:
                            cout<<"����� �Ϲ���Ʊ"<<endl;
                            break;
                        case 4:
                            cout<<"����� ������Ʊ"<<endl;
                            break;
                    }
                    yourgame.things[21+tempi]++;
                    delay(35*ut);
                    break;
                case 2:
                    cout<<endl<<"���� ������"<<endl;
                    delay(45*ut);
                    cout<<endl<<"��ѡ��Ʒ��"<<endl;
                    delay(30*ut);
                    cout<<endl<<"1.��ݮ��ƽ��\n2.���ʽ�ƽ��\n3.���ѽ�ƽ��\n4.�۹Ͻ�ƽ��\n";
                    delay(60*ut);
                    tempi=input(tempi);
                    while(tempi>4 || tempi<1){
                        cout<<"�����������������룺"<<endl;
                        delay(25*ut);
                        tempi=input(tempi);
                    }
                    delay(30*ut);
                    switch (tempi){
                        case 1:
                            cout<<"����� ��ݮ��ƽ��"<<endl;
                            break;
                        case 2:
                            cout<<"����� ���ʽ�ƽ��"<<endl;
                            break;
                        case 3:
                            cout<<"����� ���ѽ�ƽ��"<<endl;
                            break;
                        case 4:
                            cout<<"����� �۹Ͻ�ƽ��"<<endl;
                            break;
                    }
                    yourgame.things[10+tempi]++;
                    delay(35*ut);
                    break;
                case 3:
                    cout<<endl<<"���� ������"<<endl;
                    delay(45*ut);
                    cout<<endl<<"��ѡ��Ʒ��"<<endl;
                    delay(30*ut);
                    cout<<endl<<"1.���ܲ�����\n2.�Ϲϱ���\n3.ë������\n4.ţ�̱���\n5.ţ�����";
                    delay(60*ut);
                    tempi=input(tempi);
                    while(tempi>5 || tempi<1){
                        cout<<"�����������������룺"<<endl;
                        delay(25*ut);
                        tempi=input(tempi);
                    }
                    delay(30*ut);
                    switch (tempi){
                        case 1:
                            cout<<"����� ���ܲ�����"<<endl;
                            break;
                        case 2:
                            cout<<"����� �Ϲϱ���"<<endl;
                            break;
                        case 3:
                            cout<<"����� ë������"<<endl;
                            break;
                        case 4:
                            cout<<"����� ţ�̱���"<<endl;
                            break;
                        case 5:
                            cout<<"����� ţ�����"<<endl;
                            break;
                    }
                    yourgame.things[5+tempi]++;
                    delay(35*ut);
                    break;
                 case 4:
                    cout<<endl<<"���� ������"<<endl;
                    delay(45*ut);
                    cout<<endl<<"��ѡ��Ʒ��"<<endl;
                    delay(30*ut);
                    cout<<endl<<"1.��ɫ�����\n2.��ɫ�����\n3.��ɫ�����\n4.��ɫ�����\n5.��ɫ�����\n";
                    delay(60*ut);
                    tempi=input(tempi);
                    while(tempi>5 || tempi<1){
                        cout<<"�����������������룺"<<endl;
                        delay(25*ut);
                        tempi=input(tempi);
                    }
                    delay(30*ut);
                    switch (tempi){
                        case 1:
                            cout<<"����� ��ɫ�����"<<endl;
                            break;
                        case 2:
                            cout<<"����� ��ɫ�����"<<endl;
                            break;
                        case 3:
                            cout<<"����� ��ɫ�����"<<endl;
                            break;
                        case 4:
                            cout<<"����� ��ɫ�����"<<endl;
                            break;
                        case 5:
                            cout<<"����� ��ɫ�����"<<endl;
                            break;
                    }
                    yourgame.things[16+tempi]++;
                    delay(35*ut);
                    break;
                case 5:
                    cout<<endl<<"���� ������"<<endl;
                    delay(45*ut);
                    cout<<"����� �齱ȯ"<<endl;
                    yourgame.lottery++;
                    delay(35*ut);
                    break;  
            }
            goto b;
            break;
        case 2:
            cout<<"����   ��Ʊ\n����   ��ƽ��\n����   ����\n����   �����\n����   �齱ȯ\n";
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
    cout<<endl<<"��Ʒһ����"<<endl;
    delay(35*ut);
    for (int i=0,j=0;i<38;i++){
        if (price[i]!=inf){
            w[++j]=i;
            cout<<j<<". "<<tn[i]<<"  ����Ҷ�� "<<price[i]<<"��";
            if (i>=25 && i<=37 && yourgame.things[i]) cout<<"  ����������";
            cout<<endl;
            delay(4*ut);
        }
    }
    cout<<endl<<"�������е���Ҷ������  "<<yourgame.clover<<endl;
    delay(36*ut);
    cout<<endl;
    delay(40*ut);
    cout<<"ѡ�"<<endl<<"��1~19��.������Ʒ����Թ���"<<endl;
    cout<<"20.�ؼ�"<<endl<<"21.ȥ��԰"<<endl<<"22.�ص����̵ꡱ����"<<endl;
    delay(28*ut);
    tempi=input(tempi);
    while(tempi>22 || tempi<1){
        cout<<"�����������������룺"<<endl;
        delay(25*ut);
        tempi=input(tempi);
    }
    delay(27*ut);
    if (tempi<=19){
        if (yourgame.clover<price[w[tempi]]){
            cout<<"�����е���Ҷ�ݲ��㣡"<<endl;
        }
        else if (w[tempi]>=25 && w[tempi]<=37 && yourgame.things[w[tempi]])
        {
            cout<<tn[w[tempi]]<<"����Ѿ������ˣ�"<<endl<<endl;
        }
        else{
            yourgame.clover-=price[w[tempi]];
            yourgame.things[w[tempi]]++;
            cout<<"�ѳɹ�����"<<tn[w[tempi]]<<"��ʣ����Ҷ������  "<<yourgame.clover<<endl<<endl;
            if (rand()<500){
                cout<<endl<<"�������   �齱ȯ  1"<<endl;
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
