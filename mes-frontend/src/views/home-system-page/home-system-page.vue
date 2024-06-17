<template>
  <!--系统首页-->
  <p>系统首页</p>
  <!--设备总数等四小块-->
  <div>
    
    <el-row :gutter="16">
      <el-col :span="6">
        <div class="statistic-card">
          <el-statistic :value="98500">
            <template #title>
              <div style="display: inline-flex; align-items: center">
                <p>设备总数</p>
                <el-tooltip
                  effect="dark"
                  content="系统设备总数"
                  placement="top"
                >
                  <el-icon style="margin-left: 4px" :size="12">
                    <Warning />
                  </el-icon>
                </el-tooltip>
              </div>
            </template>
          </el-statistic>
        </div>
      </el-col>
      <el-col :span="6">
        <div class="statistic-card">
          <el-statistic :value="693700">
            <template #title>
              <div style="display: inline-flex; align-items: center">
                <p>运行中</p>
                <el-tooltip
                  effect="dark"
                  content="设备运行数量"
                  placement="top"
                >
                  <el-icon style="margin-left: 4px" :size="12">
                    <Warning />
                  </el-icon>
                </el-tooltip>
              </div>
            </template>
          </el-statistic>
        </div>
      </el-col>
      <el-col :span="6">
        <div class="statistic-card">
          <el-statistic :value="72000" title="New transactions today">
            <template #title>
              <div style="display: inline-flex; align-items: center">
                <p>待机</p>
                <el-tooltip
                  effect="dark"
                  content="系统设备待机数量"
                  placement="top"
                >
                  <el-icon style="margin-left: 4px" :size="12">
                    <Warning />
                  </el-icon>
                </el-tooltip>
              </div>
            </template>
          </el-statistic>
        </div>
      </el-col>
      <el-col :span="6">
        <div class="statistic-card">
          <el-statistic :value="72000" title="New transactions today">
            <template #title>
              <div style="display: inline-flex; align-items: center">
                <p>故障</p>
                <el-tooltip
                  effect="dark"
                  content="系统设备故障数量"
                  placement="top"
                >
                  <el-icon style="margin-left: 4px" :size="12">
                    <Warning />
                  </el-icon>
                </el-tooltip>
              </div>
            </template>
          </el-statistic>
        </div>
      </el-col>
    </el-row>
  </div>

  <!--表格-->
  <div>
    
    <el-table :data="tableData" stripe style="width: 100%">
      <el-table-column prop="date" label="Date" width="180" />
      <el-table-column prop="name" label="Name" width="180" />
      <el-table-column prop="address" label="Address" />
    </el-table>
  </div>

  <!--折线图-->
  <div>
    <div class="page-line-chart">
      <h4>简单折线图</h4>
      <ve-line :data="chartData"></ve-line>
    </div>
  </div>
  <div>
    <!--雷达图-->
    <p>雷达图</p>
  </div>
  <div>
    <!--饼图-->
    <p>饼图</p>
  </div>
  <div>
    <!--条形图-->
    <p>条形图</p>
  </div>
</template>

<script lang="ts" setup>
  //四小块设置
  import {
  ArrowRight,
  CaretBottom,
  CaretTop,
  Warning,
  } from '@element-plus/icons-vue'

  //表格设置
  const tableData = [
    {
      date: '2016-05-03',
      name: 'Tom',
      address: 'No. 189, Grove St, Los Angeles',
    },
    {
      date: '2016-05-02',
      name: 'Tom',
      address: 'No. 189, Grove St, Los Angeles',
    },
    {
      date: '2016-05-04',
      name: 'Tom',
      address: 'No. 189, Grove St, Los Angeles',
    },
    {
      date: '2016-05-01',
      name: 'Tom',
      address: 'No. 189, Grove St, Los Angeles',
    },
  ]

  //折线图设置
  import { reactive } from 'vue';

  const chartData = reactive({
    columns: ["日期", "访问用户", "下单用户", "下单率"],
    rows: [
      { 日期: "1/1", 访问用户: 1393, 下单用户: 1093, 下单率: 0.32 },
      { 日期: "1/2", 访问用户: 3530, 下单用户: 3230, 下单率: 0.26 },
      { 日期: "1/3", 访问用户: 2923, 下单用户: 2623, 下单率: 0.76 },
      { 日期: "1/4", 访问用户: 1723, 下单用户: 1423, 下单率: 0.49 },
      { 日期: "1/5", 访问用户: 3792, 下单用户: 3492, 下单率: 0.323 },
      { 日期: "1/6", 访问用户: 4593, 下单用户: 4293, 下单率: 0.78 }
    ]
  });

</script>


<style scoped>
  /* div{
    border: 1px solid green;
  } */
  .statistic-card {
    border: 1px solid black;
  }
  :global(h2#card-usage ~ .example .example-showcase) {
    background-color: var(--el-fill-color) !important;
  }

  .el-statistic {
    --el-statistic-content-font-size: 28px;
  }

  .statistic-card {
    height: 100%;
    padding: 20px;
    border-radius: 4px;
    background-color: var(--el-bg-color-overlay);
  }

  .statistic-footer {
    display: flex;
    justify-content: space-between;
    align-items: center;
    flex-wrap: wrap;
    font-size: 12px;
    color: var(--el-text-color-regular);
    margin-top: 16px;
  }

  .statistic-footer .footer-item {
    display: flex;
    justify-content: space-between;
    align-items: center;
  }

  .statistic-footer .footer-item span:last-child {
    display: inline-flex;
    align-items: center;
    margin-left: 4px;
  }

  .green {
    color: var(--el-color-success);
  }
  .red {
    color: var(--el-color-error);
  }
</style>
