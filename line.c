void construct_line(float x, float y, float x1, float y1)
{
	float slope, Mx, My, d = 0, b;
	float new_X = x, new_Y = y;
	slope = (y1-y)/(x1-x);
	b = (slope * x)	- y;
    if(slope >= 0  && slope <= 1)
	{
	while(x < x1)
	{
		if (new_X == x && new_Y == y)
		{
			write_pixel(new_X,new_Y);
			Mx = new_X + 1; My = new_Y + 1/2; /*Please check the floating point problem here*/
			d = (slope * Mx) + b - My;
		}
		
		else if (d <= 0)
		{
			new_X = x + 1; new_Y = y +1;
			write_pixel(new_X,new_Y);
			Mx = new_X + 1; My = new_Y + 1/2;
			d = (slope * Mx) + b - My;
		}
		
		else if(d > 0)
		{
			new_X = x + 1;
			write_pixel(new_X,new_Y);
			Mx = new_X + 1; My = new_Y + 1/2;
			d = (slope * Mx) + b - My;
		}
			
	}
	}
	
	    if(slope > 1)
	{
	while(y < y1)
	{
		if (new_X == x && new_Y == y)
		{
			write_pixel(new_X,new_Y);
			Mx = new_X + 1/2; My = new_Y + 1; /*Please check the floating point problem here*/
			d = (slope * Mx) + b - My;
		}
		
		else if (d <= 0)
		{
			new_X = x + 1; new_Y = y +1;
			write_pixel(new_X,new_Y);
			Mx = new_X + 1; My = new_Y + 1/2;
			d = (slope * Mx) + b - My;
		}
		
		else if(d > 0)
		{
			new_Y = y + 1;
			write_pixel(new_X,new_Y);
			Mx = new_X + 1/2; My = new_Y + 1;
			d = (slope * Mx) + b - My;
		}
			
	}
	}
}