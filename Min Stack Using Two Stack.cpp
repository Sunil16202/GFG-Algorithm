// https://www.interviewbit.com/problems/min-stack/
stack<int> ss;
stack<int> s;

MinStack::MinStack() {
    while(!s.empty()){
        s.pop();
    }
    while(!ss.empty()){
        ss.pop();
    }
}

void MinStack::push(int x) {
    s.push(x);
    if(ss.size() == 0 || ss.top() >= x){
        ss.push(x);
    }
}

void MinStack::pop() {
   if(s.size() == 0){
       return;
   }
   int ans = s.top();
   s.pop();
   if(ss.top() == ans){
       ss.pop();
   }
}

int MinStack::top() {
    if(s.size()>0){
        return s.top();
    }
    return -1;
}

int MinStack::getMin() {
   if(ss.size() == 0){
       return -1;
   }
   return ss.top();
}