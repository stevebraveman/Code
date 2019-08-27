void build(int x) {
	if (!top) {
		st[++top] = x;
		return;
	}
	int lca = LCA(st[top], x);
	if (lca == st[top]) return;
	while (top && id[st[top - 1]] >= id[lca]) {
		v[st[top - 1]].push_back(st[top]);
		top--;
	}
	if (lca != st[top]) {
		v[lca].push_back(st[top]);
		st[top] = lca;
	}
	st[++top] = x;
}