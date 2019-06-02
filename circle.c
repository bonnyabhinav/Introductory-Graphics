void construct_circle(Xc,Yc,R)
{
	float p,x,y;
	x = R; y = 0;
	p = 5/4 - x;

	while(y<=x)
	{
		if (p<=0)
		{
			x = x;
			y = y + 1;
			p = p + (2*y) + 1;
			x_new = x + Xc;
			y_new = y + Yc;
			write_pixel(x_new,y_new,1.0);
			write_pixel(y_new,x_new,1.0);
			write_pixel(-x_new,y_new,1.0);
			write_pixel(-y_new,x_new,1.0);
			write_pixel(-x_new,-y_new,1.0);
			write_pixel(-y_new,-x_new,1.0);
			write_pixel(x_new,-y_new,1.0);
			write_pixel(y_new,-x_new,1.0);
		}
		if (p>0)
		{
			x = x - 1;
			y = y + 1;
			p = p + (2*y) + 1 - (2*x);
			x_new = x + Xc;
			y_new = y + Yc;
			write_pixel(x_new,y_new,1.0);
			write_pixel(y_new,x_new,1.0);
			write_pixel(-x_new,y_new,1.0);
			write_pixel(-y_new,x_new,1.0);
			write_pixel(-x_new,-y_new,1.0);
			write_pixel(-y_new,-x_new,1.0);
			write_pixel(x_new,-y_new,1.0);
			write_pixel(y_new,-x_new,1.0);
		}
	}
}