    int maxProfit(vector<int> &prices) {
     vector<int>::iterator ii;
     if (prices.size() < 2) return 0;
     int profit = 0;
     int max = -1;
     for( ii = prices.end() - 1 ; ii != prices.begin() - 1 ; ii-- )
     {
      if ( (max - *ii) > profit )
	profit = max - *ii;
      if (*ii > max )
	max = *ii;
     }
     return profit;
    }
