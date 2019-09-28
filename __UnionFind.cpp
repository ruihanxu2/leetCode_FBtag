int find(int x){
	if(parent[x]!=x) parent[x] = find(parent[x])
	return parent[x]
}

void uni(int x, int y){
	a = find(x);
	b = find(y);
	if(a == b) return;
	else if(rank[a] < rank[b]){
		parent[a] = b; 
	}
	else if(rank[b] < rank[a]){
		parent[b] = a;
	}
	else{
		parent[a] = b;
		rank[b]++;
	}
	return;
}