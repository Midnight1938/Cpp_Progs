import time
def moon_phase(year, month, day) :
    c = e = jd = b = 0;
    if (month < 3) :
        year-=1;
        month += 12;
    
    month+=1;
    c = 365.25 * year;
    e = 30.6 * month;
    jd = c + e + day - 694039.09;
    #jd is total days elapsed
    jd /= 29.5305882;
    #divide by the moon cycle
    b = (int) jd;
    #int(jd) -> b, take integer part of jd
    jd -= b;
    #subtract integer part to leave fractional part of original jd
    b = round(jd * 8);
    #scale fraction from 0-8 and round
    if (b >= 8) :
        b = 0;
        #0 and 8 are the same so turn 8 into 0
    
    if (b == 0) :
        return 'New Moon';
    elif (b == 1) :
        return 'Waxing Crescent Moon';
    elif (b == 2) :
        return 'Quarter Moon';
    elif (b == 3) :
        return 'Waxing Gibbous Moon';
    elif (b == 4) :
        return 'Full Moon';
    elif (b == 5) :
        return 'Waning Gibbous Moon';
    elif (b == 6) :
        return 'Last Quarter Moon';
    elif (b == 7) :
        return 'Waning Crescent Moon';
    else :
        return 'Error';

timestamp = int(time.time());
print(moon_phase(date('Y', timestamp), date('n', timestamp), date('j', timestamp)),end="");