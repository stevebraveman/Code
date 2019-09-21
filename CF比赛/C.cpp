#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
ll wx1, wx2, wy1, wy2, bx11, bx21, by11, by21, bx12, bx22, by12, by22;
ll sqw, sqb1, sqb2;
struct sqr {
	int x1, y1, x2, y2;
}w, b1, b2;
int sqr(sqr a,  sqr b) {
	int xmin = std::min(a.x1, b.x1);
	int xmax = std::max(a.x2, b.x2);
	int ymin = std::min(a.y1, b.y1);
	int ymax = std::min(a.y2, b,y2);
}
int main(){
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d", &wx1, &wy1, &wx2, &wy2, &bx11, &by11, &bx21, &by21, &bx12, &by12, &bx22, &by22);
	w.x1 = wx1;
	w.x2 = wx2;
	w.y1 = w.y1;
	w.y2 = w.y2;
	b1.x1 = bx11;
	b1.x2 = bx21;
	b1.y1 = by11;
	b1.y2 = by21;
	b2.x1 = bx12;
	b2.x2 = bx22;
	b2.y1 = by12;
	b2.y2 = by22;

}