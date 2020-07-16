
struct DSU{
    vi parent,size;
    int cmp;
    void init(int N){
        parent.resize(N),size.resize(N);
        cmp=N;
        for(int i=0;i<N;++i){
            parent[i]=i;
            size[i]=1;
        }
    }
    int find_set(int x){
        if(parent[x]==x) return x;
        return parent[x]=find_set(parent[x]);
    }
    int set_size(int x){
        return size[find_set(x)];
    }
    int num_cmp(){
        return cmp;
    }
    bool same_set(int a,int b){
        return find_set(a)==find_set(b);
    }
    int get_sz(int x){
        return size[find(x)];
    }
    void merge(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            cmp--;
        }
    }
};
