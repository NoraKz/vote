## 开发

[开发任务列表](./task)

## 编译

### 前置工具

- CMake

- Git

- Vcpkg

- 任一cmake支持的编译器

### 引入vscpkg支持

如果未安装vcpkg，可在[通过 CMake 安装和使用包 | Microsoft Learn](https://learn.microsoft.com/zh-cn/vcpkg/get_started/get-started)中找到方法。由于项目已完成CMakeLists的设置，如果你参照这个链接，仅需完成步骤1、4即可，4与我们下面的操作完全相同。

你需要在目录下新建两个文件

#### CMakePresets.json

```json
{
    "version": 2,
    "configurePresets": [
      {
        "name": "vcpkg",
        "generator": "Ninja",
        "binaryDir": "${sourceDir}/build",
        "cacheVariables": {
          "CMAKE_TOOLCHAIN_FILE": "$env{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        }
      }
    ]
}
```

你可以修改Ninja为一个你需要的编译器，例如**Visual Studio 17 2022**，可用的选项你可以通过**cmake --help**，在Generators中找到。

#### CMakeUserPresets.json

```json
{
    "version": 2,
    "configurePresets": [
      {
        "name": "default",
        "inherits": "vcpkg",
        "environment": {
          "VCPKG_ROOT": "你的vcpkg所在的路径"
        }
      }
    ]
}
```

创建完成这两个文件后，你可以进行下一步操作

### 生成

```bash
mkdir build
cd build
cmake --preset=default ..
```

```bash
cmake --build .
```

## Contributors

<a href="https://github.com/dingdinglz/vote/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=dingdinglz/vote" />
</a>

Contributor Image Made with [contrib.rocks](https://contrib.rocks).