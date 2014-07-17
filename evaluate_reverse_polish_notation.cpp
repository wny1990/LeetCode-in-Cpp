int evalRPN(vector<string> &tokens)
{
    stack<int> opn;
    vector<string>::iterator ii;
    for(ii = tokens.begin(); ii != tokens.end(); ++ii )
    {
        if ( *ii == "+" || *ii == "-" || *ii == "/"|| *ii == "*")
        {
            int op2 = opn.top();
            opn.pop();
            int op1 = opn.top();
            opn.pop();
            int op3 = 0;
            if (*ii == "+")
                    op3 = op1 + op2;
            if (*ii == "-")
                    op3 = op1 - op2;
            if (*ii == "*")
                    op3 = op1 * op2;
            if (*ii == "/")
                    op3 = op1 / op2;
            opn.push(op3);
        }
        else
        {
            stringstream s_str(*ii);
            int op;
            s_str >> op;
            opn.push(op);
        }
    }
    return opn.top();
}
