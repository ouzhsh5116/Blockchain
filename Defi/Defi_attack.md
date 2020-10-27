# Defi中的攻击事件

- Balancer
  - **2020年6月29日凌晨（北京时间），Balancer项目的两个资金池遭受攻击。攻击者在此次事件中获利约46万美元，资金池市商损失约50万美元。**
  - 攻击者利用Balancer 资金池与通缩货币结合产生的漏洞，盗取资金池500,000美元。
  - 随后不仅，攻击者利用Compound“借贷即挖矿”的特性，窃取了资金池中无人认领的Comp币。
- 币安智能链
  - 9 月 19 号，币安智能链上的项目 Bantiample 团队已砸盘套现 3000 个 BNB 跑路，目前团队的主要开发者已经删除 Telegram 账号，项目代币 BMAP 单日跌幅超过 90%。
- 以太坊挖矿项目 LV Finance 项目疑似跑路，该项目通过伪造虚假审计网站并提供虚假审计信息诱骗投资者进行投资，待一段时间后资金池内金额足够大时进行跑路。目前，该项目网站 lv.finance 已无法访问。
- 废老师（微博用户名「废 X 废」）参与了流动性挖矿项目 Soda 发现有一个漏洞，里面有 2 万个 ETH 可以直接清算掉。但他选择了告诉开发组，但开发组并未重视。他只好选择清算了一个 ETH，并发微博警告，实操告诉开发者这个 Bug 的存在。不到一个小时，项目组发布公告:在前端停止借款的功能，如果有人因为这个 bug 收到了损失，我们在未来会尽可能推出补偿方案。
- 以太坊研发者 Philippe Castonguay 发推文称，DeFi 项目 BaconSwap 和 shroom.finance 均存在时间锁定漏洞，将允许项目所有者在没有时间锁定的情况下增发无限代币。
- 推特账户名为 Amplify 的用户透露自己在新 DeFi 项目 Soft Finance 中因系统漏洞而获利 25 万美元。并称自己并非作恶者，只是无意中发现了这个「机会」。
- 波场 DeFi 项目樱桃 CherryFi 在电报群表示，USDT 合约在迁移过程中由于一行代码导致无法提取 USDT，损失 USDT 的用户可以联系管理员，团队将给出一个赔偿方案，建议用户都把 TRX 提走。据了解，CherryFi 代码未经审计。
- EOS 项目 EMD 疑似跑路，截至目前，项目合约 emeraldmine1 已向攻击者账号 sji111111111 转移 78 万 USDT, 49 万 EOS 及 5.6 万 DFS，并有 12.1 万 EOS 已经转移到 changenow 洗币平台。
- EOS 挖矿项目珊瑚的 wRAM 遭到黑客「重入」攻击，损失超 12 万 EOS。攻击者账号采用了类似「重入攻击」的模式，对 eoswramtoken 合约实施了攻击。具体而言，攻击者在正常的转账操作内嵌入了一次 inline transfer，使得 wRAM 合约在 mint 时判断 RAM 数额出现问题导致多发。
- yearn.finance 创始人 Andre Cronje 刚推出的游戏项目 Eminence（ENM）遭遇「Flash 贷款」攻击，黑客将 800 万美元的资金返还给了 yearn 部署者合约。官方目前正在调查具体情况，并将重新分配受攻击的 800 万美元。



### Reference

[Defi 上的安全事件](https://www.theblockbeats.com/news/20003)