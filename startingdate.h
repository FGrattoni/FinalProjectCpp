void Start(int i=0){
    if (i==0){
        int start[]= {0,1};
        cout << "Hello,\n";
    }
    cout<< "When would you like to start your repayment schedule? Please enter: month[_ _]\n";
    cin >> start[0];
    cout<< "Please enter four digits: year[_ _ _ _]\n";
    cin >> start[1];
    if (start[0]>12 || start [0]<1)
        {
            cout<< "Your input is not valid. Please enter a number of (1,2,3,4,5,6,7,8,9,10,11,12): month[_ _]\n";
            cin >> start [0];
        }
    if (start[1]>2039 || start [1]<2019)
        {
        cout<< "Your input is not valid. Please select a date between 2019 & 2039 : year[_ _ _ _]\n";
        cin >> start [0];
        }
    if (start[0]<4 && start [1]=2019)
        {
        cout<< "Your input is not valid. Please select a date in the future\n";
        cin >> start [0];
        Start(i=1)
        }
    cout << "The selected starting date is" << start[];
}
