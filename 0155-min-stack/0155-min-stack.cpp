class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {}

    void push(int value) {
        if (st.empty()) {
            st.push(value);
            mini = value;
            return;
        }

        if (value > mini) {
            st.push(value);
        } else {
            // SAFE: no overflow now
            st.push(2LL * value - mini);
            mini = value;
        }
    }

    void pop() {
        if (st.empty()) return;

        long long x = st.top();
        st.pop();

        if (x < mini) {
            mini = 2 * mini - x;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long x = st.top();
        return (x > mini) ? x : mini;
    }

    int getMin() {
        return mini;
    }
};
