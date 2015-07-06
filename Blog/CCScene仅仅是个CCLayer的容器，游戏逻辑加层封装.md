##  游戏逻辑在CGameLogic实现，并加入Layer中 ##

1. CCScene仅仅是个CCLayer的容器，游戏逻辑甚至界面元素都不会直接加入到Scene中。

2. CCLayer会加入界面元素，这是肯定的，比如：游戏menu, button，或显示的label等。游戏状态的显示，游戏设置，一定是在Layer中实现的。

3. 但CCLayer中应该加入游戏逻辑吗？ 可以加入，很多游戏是这样做的，把精灵加入到CCLayer中，处理精灵的各种逻辑操作和行为。但这样并不好，比较好的做法是通过一个逻辑类来代替Layer完成这个工作。我们可以这样做，从CCNode继承一个新类，例如叫CGameLogic （或者CSpriteManager etc，根据功能起名字）
然后把精灵加入到CGameLogic，在这个类中，完成精灵的状态控制，游戏逻辑的实现。然后把CGameLogic加入到CCLayer中，这样CCLayer是游戏逻辑的容器，而不是游戏逻辑的实现。这样做的好处就是实现了逻辑和显示的分离，好处是很明显的，对以后的游戏维护，扩展以及组件的重用都是有好处的。如：
    	
		LayerManager::moveSpirteToTop(CCSprite* sprite, CCPoint point)