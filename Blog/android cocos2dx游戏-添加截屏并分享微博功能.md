## 分享部分 ##
#### 安卓代码 ####

```java
    public class ShareSupport {
    	// when you want to use share(),firstly you should init acty.
    	public static Activity acty;
    
    	public static void share() {
    		new Thread(new Runnable(){
    
    			@Override
    			public void run() {
    			Intent intent = new Intent("android.intent.action.SEND");  
    			intent.setType("image/*");  
    			intent.putExtra(Intent.EXTRA_SUBJECT, "分享");  
    			intent.putExtra(Intent.EXTRA_TEXT, "终于可以了!!!");
    			intent.putExtra(Intent.EXTRA_STREAM,Uri.parse("file:////data/data/" + acty.getApplicationInfo().packageName+ "/share.png"));
			    Log.i("debug", "/data/data/" + acty.getApplicationInfo().packageName+ "/share.png");
			    intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK); 
			    acty.startActivity(Intent.createChooser(intent, "分享")); 
    			}
    
    		}).start();
    	}
    }
```

#### JNI代码 ####
```c++
	#include "jni_interfaces.h"
	#include <android/jni/JniHelper.h>
	
	extern "C" {
	    void Share()
	    {
	        cocos2d::JniMethodInfo jni_method_info;
	        cocos2d::JniHelper::getStaticMethodInfo(jni_method_info,"com/hortor/support/ShareSupport","share","()V");
	
	        if (jni_method_info.methodID)
	        {
	            jni_method_info.env->CallStaticVoidMethod(jni_method_info.classID, jni_method_info.methodID);
	        }
	    }
	}
```
#### C++代码 ####
```c++
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	  Share();
	  CCLog("share ok");
	#endif
```
## 截屏部分的代码 ##
```c++
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCRenderTexture* in_texture = CCRenderTexture::renderTextureWithWidthAndHeight((int)size.width, 			      (int)size.height,kCCTexture2DPixelFormat_RGBA8888);
    in_texture->getSprite()->setAnchorPoint( ccp(0.5f,0.5f) );
    in_texture->setPosition( ccp(size.width/2, size.height/2) );
    in_texture->setAnchorPoint( ccp(0.5f,0.5f) );

    in_texture->begin();
    this->visit();
    in_texture->end();

    CCLog("%d",in_texture->saveBuffer(kCCImageFormatPNG,"share.png",0,0,800,480));
```
