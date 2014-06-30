    int maxArea(vector<int> &height) {
     vector<int>::iterator ii,jj;
     int area = 0;
     for(ii=height.begin(); ii!=height.end();ii++)   
     	for(jj=ii+1; ii!=height.end();jj++)   
		if ( (jj-ii)*(*ii+*jj) > area)
			area = (jj-ii)*(*ii+*jj);
	return area/2;
    }
