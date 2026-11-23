class ProductOfNumbers {
public:
    vector<long long int> nums,prod;
    ProductOfNumbers() {
        nums={};
        prod={};
    }
    
    void add(int num) {
        nums.push_back(num);
        for(int i=prod.size()-1;i>=0;i--){
            prod[i]=prod[i]*num;
        }
        prod.push_back(num);
    }
    
    int getProduct(int k) {
        return prod[prod.size()-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */