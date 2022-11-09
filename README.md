# Trading Backtester
A simple trading backtesting program written in C++. You can use this program to simulate trading based upon your trading system and win rate.
(Warning: Fees calculation may not be accurate. Needs to be improved)

# Prerequisites
This program does not have an accurate fee calculation, so simulation results may not be accurate.
Will be updated, stay tuned.

# How to Use
Simply download "Backtester" and it will open up as a terminal executable. From there, you can put in your parameters.

# Parameters
Here are the parameters and their explanation:
- How many trades?: How many trades you want to simulate.

- Starting balance?: Your starting balance.

- Winrate %?: Your winrate in percentage number.

- What leverage?: Your leverage size, if any. If you don't use leverage, enter 1.

- Take profit %?: Your take profit percentage based on market movement.
Example: If you set your take profit by 1(%), then if the market price moves up by 1% then your take profit will be hit.

- Stop loss %?: Your stop loss percentage based on market movement.

- Market order fee %?: Your exchange/platform market/taker order fee in percentage.

- Limit order fee %?: Your exchange/platform limit/maker order fee in percentage.
