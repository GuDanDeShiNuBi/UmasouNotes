##### 风险管理


1、规划风险管理
    规划风险管理定义了如何实施项目风险管理活动的过程，对接下来风险管理工作进行了指导。在项目初期，我结合项目管理计划、项目章程、干系人登记册等资料，邀请公金融信创专家、业务骨干、IT架构师及团队成员，以专题会议的形式对风险管理策略、风险责任人、风险类别、管理应急储备、概率和影响矩阵等方面进行了讨论，共同制定了风险管理计划。在计划中，我们还确定了每两周召开一次风险评估会议，评估项目活动的最新风险状态。

2、识别风险
    风险识别是判断哪些风险会对项目产生影响并记录过程。项目初期，我根据项目的实际情况，将风险划分为技术风险、管理风险和外部风险三大类，使用风险分解结构（RBS）列出已知的风险，然后进一步细化这些已识别的风险，形成包含风险描述、潜在责任人和潜在应对措施的风险登记册。在识别项目风险时，我与团队成员还利用核对单法，基于金融OA系统常见风险清单，排查出 “国产数据库性能不足”“跨系统数据格式不统一” 等 18 项风险；风险的识别是个持续的过程，任何阶段都有可能发生不可预知的风险，我要求团队成员通过10分钟的每日站会分享和记录可能的风险，并在每个迭代周期的迭代回顾会议上进行评审。
    
3、实施定性风险分析
    定性风险分析是分析和评估风险的概率和影响，并对风险进行优先级排序的过程。我们组织公司财务、行政、人资等部门通过会议对已识别的风险进行概率和影响评估，我们采用头脑风暴的方法来确定每个风险发生的可能性以及对项目的影响，最后再进行进行风险优先级的排序。在这一过程中，我们为风险登记册添加了责任人、概率、影响、分值、风险类别和策略等新的信息，结合这些信息确定了前五大风险，1、数据安全合规不达标
    2、国产数据库性能缺陷；3、业务流程重构受阻；4、跨系统集成接口失败 5、关键用户培训效果差
    
4、实施定量风险分析
   定量风险分析是对风险进行量化计算和分析并将结果汇总更新到风险登记册中的过程，其中量化的工具包括蒙特卡洛分析、敏感性分析。因为此次项目本身架构清晰，而项目组成员又对类似项目经验丰富，前期识别到的风险都完全处在可控范围内，所以我们根据项目管理的裁剪原则，研究评审后决定跳过实施定量风险分析过程。
   组织专家，对风险清单上的风险进行定量分析，根据风险登记册，风险报告，采用敏感性分析法，把各项风险的影响转化为量化数据，与项目持续时间相关联，如需求蔓延对项目的影响变动是30天，人员流动对项目的影响变动是10天，设备到货时间对项目的影响变动是15天。



5、规划风险应对
   规划风险应对就是针对正面风险和负面风险，制定不同应对措施，以提高项目成功的机会或降低项目失败的威胁。我们以风险管理计划和最新的风险登记册为依据，分析各个风险应如何应对，最后将应对计划更新到风险登记册。
   由于该项目是在原有的系统基础上升级改造，新旧系统数据结构存在差异，导致部分旧系统审批数据可能无法导入新系统。为了解决这个问题，我们讨论后决定，未来能导入新系统的数据尽量导入，万一遇到无法导入的旧数据，先用文件存档，再以图片的形式保存审批流程截图。通过以上措施，我们能够在系统切换到新系统后尽量保留原有的数据，以确保公司业务的顺利进行。

6、实施风险应对
    有了完善的管理计划，更应按计划贯彻执行。实施风险应对是执行商定的风险应对计划的过程。例如针对数据安全合规不达标的风险，我们直接引入了第三方测评机构，以此来转移合规审查的风险。对于国产数据库性能缺陷的问题，我与团队成员提前进行压力测试，模拟 5000 并发审批，并与架构师商讨，采购了国产数据库性能优化工具，并预留 2 套硬件集群备用；
7、监督风险
    监督风险是在整个项目周期，跟踪已识别的风险、识别新风险以及评估风险过程有效性的过程。我们依据项目管理计划、绩效数据、风险登记册等资料，进行风险监督。具体而言，我以1-2周为节点，在风险评审会或敏捷的迭代回顾会议中与团队成员一起评估风险是否变化，是否有新的风险出现，并且对已出现的风险评估应对措施执行的有效性。另外，还有公司审计部会定期实行风险审计，形成审计底稿。经过有效的风险监督，对项目目标的达成奠定了基础。
