Introduction in Chinese:
�ļ��ṹ����Ҫ���ܣ� 
Core\Basic\ 
Assert: ���Լ�⣬ SLOW_ASSERT����console printλ�ã�������Ϣ��
Target & BasicType: ƽ̨�޹ز��������Ͷ���
BasicFunction: ������������С������ת����float��⼰�Ƚϣ�rand������
FileIO & LuaData: : �ļ����뼰Lua֧�֣�Lua�����ȡ
Core\Math\
����Box2D, Vector2,3,4, Matrix���࣬Matrix����ʹ��SIMD
Core\Memory\
�ڴ���������ѷ��������̶���С�ڴ�ط�����������new���أ��ڴ�������ȵ�
Core\String\
�����ַ�����ϣ�࣬�ַ����ؼ������ַ����ࣨ�ַ������� �ַ����ķ�װ�ࣩ��
Core\Template
��������ָ�룬strong,weak,unique pointer��ʵ�֡�������������������Array, LinkedList, List, Queue,Stack, CircleQueue��. ��������Ϊstl�����İ�װ
Core\Thread
�������������ź������¼�����д������ķ�װ

Object\
����GameObject, Actor��Pawn��GameObject������Ϸ����ʵ�����ݣ�Actorӵ��GaneObject��������ϵͳ����������������ΪgameObject����Ϊ�ṩ�ӿڣ�pawn�̳���Actor������һ��controller���������
Controller\
����һ��������IController��һ����ҿ����������ֹ�����������Ժ�Ὣ�Զ���������Ƴ����棩���Լ�һ������������������������������һ��pawn����������Ϊ��������������ӵ�����еĿ�������������¡�
SubSystem\Job
��ҵϵͳ������ϸ���ȵĶ��߳�����JobSystem��������һ�����ֺ���������м��̶߳��ж�Ӧ��map�����԰��������͵�������У���Ӧ���̶߳��г����������������ȡ����ִ�С�
Jobs\
��ҵ�����࣬����һ��������IJob��Ŀǰ����JobLoadActor��JobLoadPawn��ҵ����Ϊ�Ϸ�ʱ�Ĵ�lua�ű���ȡ�������ɶ���Ĳ���
SubSystem\Render
������Ⱦ��ϵͳ��������Ⱦ���󣨱�Actor���ӣ�����Ⱦ��������ӵ�в��������͸�������actor��pawn��renderObject����ͬʱ��Ⱦ��������������������Ϸ��ͼ����Դ����֤��Դ���ڴ�Ψһ�ԡ�
SubSystem\Physics
����������ϵͳ������������󣨱�Actor���ӣ��������������ӵ�в���������������󣩣���������Actor�Ľӿ���Controller�ṩ���ݣ�Euler Methodģ���ٶȱ仯���˶�
Manager\
������Ϸʱ�����ʵʱ�����������CPU�߾���ʱ��ʵ�֣������ṩʱ�������߳�����֡��
�������������GLib�ص��������£�
��������������������ӵ������Actor��Pawn�����ṩActor��Pawn�����ɷ���������Pawn����ʱ����ݶ�����������Controller�������������֤������֡ǰ�������ɾ������֤֡�ڸ�����Ϊ�İ�ȫ��
Component\
����������Componenet transform��������IComponent
Engine\
������������������ںͳ��ڡ�

EngineTest
main.cpp��������ϵͳ��UnitTest

Game
Game\Assets
������Ϸ���õ���lua�ű���һЩ���Ƶļ�sprite

main.cpp
�߲���Ϸ��Ϊ��Ŀǰ�൱�򵥣���������͸�����ϵͳ������Actor��Pawn�����¡�������ֹ���棬������ڴ�й©




Update list:
V1.00
A 2D version of MonsterChase, hope you like it.
The entrance is in Game/main.cpp. I made MonsterChase project as a static library of the Game project.
10 monster were created in the beginning. 2 different monsters' move patterns were supported with the define (Focus On Player or Move Randomly). A Sleep(100) was used in loop to control the update speed.
The green node represents player, and red nodes represent monsters. I feel sorry for my art works.
No memory leak. Some warnings about pdb files in release version.
If there are any questions, please let me know.


V1.01
A input manager was added into Engine/Manager/InputManager.h  , a enum class(Key) was used to define the name of each key

You can close the application by press ESC

You can move by press A,S,D,W, it support 8 directions move
I finished the physics calculation about player's movement using Euler method. 
Since now there still a lot of problems to solve, I didn't make a physics Manager.

Besides, I made a singleton for TimeManager in Engine/Manager/TimeManager.h to offer information for other sub-system. It will only update in the main loop.
FPS will be printed in the output window.

Thank you for checking, if there are any questions, please let me know.


V1.02
Implement Big end and small end transfer for some types such as INT, FLOAT
Implement Vector4, Matrix, Triangle, Cube.
Use ForceInline, delete -inl.h file, reconstruct all classes.
Reconstruct all files in .h and .cpp. Uniform all files format and style(really time consuming, but really learned a lot)
Add support for Weak pointer and strong pointer   // in file Engine\Core\Pointers.h and Engine\Core\Private\Pointers.cpp
Add support for Container: LinkedList and List    // in file Engine\Core\Container.h 
Add unitTest for container and smart pointer      // in EngineTest\unit_test.cpp


V1.03
Reconstruct files structure of Engine project
Add simple api for unique pointer																				// in Engine\Core\Template\Pointer.h
Add RenerObject and RenderManager, RenderManager is a subsystem in this game which control all render objects.  // Engine\SubSystem\RenderManager.h
A renderObject is related to a gameobject																		// Engine\Subsystem\RenderObject.h
Replace normal pointer to smart pointer	as more as possible														// Game\main.cpp
Add StringPool, HashString and pooledString and their functions							// Engine/Core/String/


V1.04 
Reconstruct engine(maybe the last time), change file structure, change code standard.
Add stringPool into use																				         // Init in Engine/Engine/Private/Engine.cpp and use in Object/Actor.h (which store type and name)
add actor and pawn object structure																			 // Actor own gameObject and observe components, pawn inherites from Actor and observe a controller
add three kinds of controller, which control pawns, include player and monsters							     // Engine\Controller\Controller.h 
add ControllerManager, singleton which owns all controllers	(should move out of engine in the future)		 // Engine\Controller\ControllerManager.h
add WorldManager, singleton which owns all actors and pawns (Game Scene)									 // Engine\Manager\WorldManager.h	
fix bugs in FixedSizeAllocator


V1.05
add Physics objects, controllered by controller and update gameobject's parameters							 // Engine\Subsystem\PhysicsObject.h
add Physics Manager, singleton who owns all physics objects and update them				                     // Engine\SubSystem\PhysicsManage.h 
add Engine states, add Engine functions, rewrite code in Game/main.cpp relate to new structure				 // Game\main.cpp    Engine\Engine\Engine.h
add HeapManage, singleton init when the engine start. control all other new									 // Engine\Core/Memory\HeapManager.h
separate new into a new file, overload new use functions in HeapManager                                      // Engine\Core/Memory\New.h
Control all other singletons in Engine. Add static function Create, Get, Destroy into all singletons         // All singletons
add box2D class into gameobject


V1.06
add drag into physicsObject, the drag = -velocity ^ 2 * k;													 // Engine\Subsystem\PhysicsObject.h
add support for CircleQueue																					 // Engine\Core\Template\CircleQueue.h
separate loadfile function into core																		 // Engine\Core\Basic\FileIO.h												
add lua into ThirdParty\Lua, add support for lua															 // Engine\Core\Basic\LuaData.h
add Assets folder in Game and add lua script																 // Game\Assets\Data\Player1.lua
add lua load in worldManager to load actor and pawn from lua, used in Game\main.cpp        					 // Engine\Manager\WorldManager.h
modify EngineTest project into a window application, add UnitTest for lua and circleQueue					 // EngineTest\main.cpp

V1.07
big changes, provide multi-thread features
add job system into the Engine (testing), initial in Engine and ShutDown when engine shut down				 // Engine\SubSystem\Job
add some simple jobs (Load Actor and Pawn from lua) and use these jobs in Game\main.cpp						 // Engine\Jobs\
change heapAllocator and fixedSizeAllocator's operations to thread-safe operations 
// assignment notification:
Support all necessary functions within Vector4 and Matrix, some of them are done in SIMD					 // Engine\Core\Math\

V1.08
change container for PhysicsManager and RenderManger
support priority in RenderManager, objects with higher priority are rendered later							 // Engine\SubSystem\Render\RenderManager.h
add collision into actor, support debug information when they collide(in test)								 // Engine\Object\Private\Actor.cpp
add properties (canCollide, isStatic, isActive) into actor, which control collision and update				 // Engine\Object\Actor.h
change the flows of actors were added into the world. All new actors are added into a queue which will not be update in this frame,
in next frame, actors in the queue will be pushed into array which allow actors to update					 // Engine\Manager\WorldManager.h
change necessary functions in all singletons to be thread-safe to some extent, mainly controlled by critical section.
Fixed bugs within RealTimeManager, add Sleep in main thread to lock frame rate to 60 fps.					 // Engine\Engine\Engine.h
collision bugs fixed, DEBUG_PRINT when they collide